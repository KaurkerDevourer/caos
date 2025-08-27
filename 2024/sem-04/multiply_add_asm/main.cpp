#include <iostream>

// a * 2 + b
extern "C" int multiply_add(int, int);

int main() {
    int a, b;

    std::cin >> a >> b;

    int c = multiply_add(a, b);

    std::cout << c << std::endl;

}

