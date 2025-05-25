// PaddingOrderCheck.cpp

#include "clang/AST/AST.h"
#include "clang/AST/ASTContext.h"
#include "clang/AST/RecordLayout.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/Basic/Diagnostic.h"

#include "clang-tidy/ClangTidy.h"
#include "clang-tidy/ClangTidyCheck.h"
#include "clang-tidy/ClangTidyModule.h"
#include "clang-tidy/ClangTidyModuleRegistry.h"

using namespace clang;
using namespace clang::ast_matchers;
using namespace llvm;

namespace clang {
namespace tidy {
namespace misc {

class PaddingOrderCheck : public ClangTidyCheck {
public:
  PaddingOrderCheck(StringRef Name, ClangTidyContext *Context)
      : ClangTidyCheck(Name, Context) {}

  void registerMatchers(ast_matchers::MatchFinder *Finder) override {
    // Матчер для поиска определений структур и классов
    Finder->addMatcher(
        recordDecl(isDefinition()).bind("recordDecl"),
        this);
  }

  void check(const ast_matchers::MatchFinder::MatchResult &Result) override {
    const auto *RD = Result.Nodes.getNodeAs<RecordDecl>("recordDecl");
    if (!RD || RD->isUnion() || RD->field_empty())
      return;

    ASTContext &Context = *Result.Context;
    const ASTRecordLayout &Layout = Context.getASTRecordLayout(RD);

    std::vector<std::pair<const FieldDecl *, uint64_t>> Fields;
    
    // Собираем информацию о полях
    for (const FieldDecl *Field : RD->fields()) {
      if (Field->isBitField())
        continue; // Пропускаем битовые поля для упрощения
      
      QualType FieldType = Field->getType();
      uint64_t FieldSize = Context.getTypeSize(FieldType);
      uint64_t FieldAlign = Context.getTypeAlign(FieldType);
      Fields.push_back(std::make_pair(Field, FieldSize));
    }
    
    // Сортируем поля по размеру и выравниванию (от большего к меньшему)
    std::vector<std::pair<const FieldDecl *, uint64_t>> OptimalFields = Fields;
    std::sort(OptimalFields.begin(), OptimalFields.end(),
              [&Context](const std::pair<const FieldDecl *, uint64_t> &A,
                         const std::pair<const FieldDecl *, uint64_t> &B) {
                uint64_t AlignA = Context.getTypeAlign(A.first->getType());
                uint64_t AlignB = Context.getTypeAlign(B.first->getType());
                if (AlignA != AlignB)
                  return AlignA > AlignB;
                return A.second > B.second;
              });
    
    // Проверяем, совпадает ли текущий порядок с оптимальным
    bool IsOptimal = true;
    for (size_t i = 0; i < Fields.size(); ++i) {
      if (Fields[i].first != OptimalFields[i].first) {
        IsOptimal = false;
        break;
      }
    }
    
    // Вычисляем примерный размер структуры с текущим и оптимальным порядком полей
    uint64_t CurrentSize = Layout.getSize().getQuantity() * 8; // в битах
    
    // Оценка размера с оптимальным порядком (упрощенно)
    uint64_t OptimalSize = 0;
    uint64_t CurrentOffset = 0;
    uint64_t MaxAlign = 0;
    
    for (const auto &Field : OptimalFields) {
      uint64_t FieldAlign = Context.getTypeAlign(Field.first->getType());
      uint64_t FieldSize = Field.second;
      
      MaxAlign = std::max(MaxAlign, FieldAlign);
      
      // Выравнивание для поля
      CurrentOffset = (CurrentOffset + FieldAlign - 1) / FieldAlign * FieldAlign;
      CurrentOffset += FieldSize;
    }
    
    // Выравнивание всей структуры
    OptimalSize = (CurrentOffset + MaxAlign - 1) / MaxAlign * MaxAlign;
    
    if (OptimalSize < CurrentSize) {
      // Если текущий порядок не оптимален, выдаем предупреждение
      std::string Message = "Struct '" + RD->getNameAsString() + 
                            "' has suboptimal field order for padding";
      if (CurrentSize > OptimalSize) {
        Message += " (current size: " + std::to_string(CurrentSize/8) + 
                   " bytes, optimal could be: " + std::to_string(OptimalSize/8) + " bytes)";
      }
      
      diag(RD->getLocation(), Message);
    
    // Вывод каждой строки оптимальной структуры как отдельного сообщения
    diag(RD->getLocation(), "Suggested optimal struct:", DiagnosticIDs::Note);
    
    // Заголовок структуры
    diag(RD->getLocation(), "struct " + RD->getNameAsString() + " {", DiagnosticIDs::Note);
    
    // Поля структуры
    for (size_t i = 0; i < OptimalFields.size(); ++i) {
    std::string FieldDecl = "    " + OptimalFields[i].first->getType().getAsString() + " " + 
                            OptimalFields[i].first->getNameAsString() + ";";
    diag(RD->getLocation(), FieldDecl, DiagnosticIDs::Note);
    }
    
    // Закрывающая скобка структуры
    diag(RD->getLocation(), "};", DiagnosticIDs::Note);
    }
  }
};

// Регистрация модуля для включения чекера
class PaddingOrderModule : public ClangTidyModule {
public:
  void addCheckFactories(ClangTidyCheckFactories &CheckFactories) override {
    CheckFactories.registerCheck<PaddingOrderCheck>(
        "misc-padding-order");
  }
};

} // namespace misc
} // namespace tidy
} // namespace clang

// Исправленная регистрация для LLVM 14
// Используем макрос для регистрации модуля
namespace clang {
namespace tidy {

// Этот макрос регистрирует модуль в глобальном реестре
static ClangTidyModuleRegistry::Add<misc::PaddingOrderModule>
X("padding-order", "Adds padding order check");

} // namespace tidy
} // namespace clang
