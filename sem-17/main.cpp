#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Ops" << std::endl;
        std::cerr << "Wrong number of arguments" << std::endl;
        return 1;
    }
    int n = std::stoi(argv[1]);
    while(true) {
        int x;
        std::cin >> x;
        std::cout << x * n << std::endl;
        std::cerr << x << std::endl;
    }
}
