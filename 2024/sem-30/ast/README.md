# AST
это древовидное представление структуры исходного кода, которое компилятор (например, Clang, GCC) строит после парсинга.

## Где используется?

* Оптимизации компилятора (удаление мёртвого кода, инлайнинг).
* Статический анализ (Clang-Tidy, Clang Static Analyzer).
* Рефакторинг кода (автоматическое переименование, изменение структуры).
* Генерация кода (из AST можно сгенерировать LLVM IR или другой язык).

## Как посмотреть?

```
clang++ -Xclang -ast-dump -fsyntax-only struct.cpp
```

## Как скомпилировать монстра?

```
clang++-14 -shared -fPIC -o libPaddingOrderCheck.so PaddingOrderCheck.cpp \
    `llvm-config-14 --cxxflags` \
    -I/usr/lib/llvm-14/include \
    -std=c++14 \
    -fno-rtti \
    `llvm-config-14 --ldflags` \
    -L/usr/lib/llvm-14/lib \
    -lclangTidy -lclangTidyMiscModule -lclangTidyUtils \
    -lclangAST -lclangASTMatchers -lclangBasic -lclangFrontend \
    -lclangSerialization -lclangTooling -lLLVM-14
```

## Как запускать монстра?
```
clang-tidy-14 -checks='misc-padding-order' -load=optimizer/libPaddingOrderCheck.so struct.cpp -- -std=c++14
```

А то, что он падает - нормально. Отдебажить такое невозможно. Если мы хотим настоящий работающий, надо скачивать llvm, и там через честные скрипты делать. Можно посмотреть сюда: https://habr.com/ru/companies/auriga/articles/526486/
Однофайликом только так.
