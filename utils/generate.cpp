#include <iostream>
#include <fstream>
#include <string>
#include <random>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Использование: " << argv[0] << " <имя_файла> <количество_чисел>\n";
        return 1;
    }

    const std::string filename = argv[1];
    const int count = std::stoi(argv[2]);

    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Ошибка: не удалось открыть файл для записи: " << filename << "\n";
        return 1;
    }

    file << count << "\n";

    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> distrib(1, 100);

    for (int i = 0; i < count; ++i) {
        file << distrib(gen) << "\n";
    }

    std::cout << "Файл '" << filename << "' успешно создан с " << count << " числами.\n";
    return 0;
}
