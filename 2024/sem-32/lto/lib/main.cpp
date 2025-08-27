#include <iostream>
#include "lib.h"

int main() {
    Derived d;
    call_virtual(&d);  // Виртуальный вызов
    call_external();   // Вызов из разделяемой библиотеки
    return 0;
}
