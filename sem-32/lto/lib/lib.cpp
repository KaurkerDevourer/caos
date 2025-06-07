#include "lib.h"

void call_virtual(Base* b) {
    b->foo();  // Косвенный вызов через vtable
}

void call_external() {
    std::cout << "External call\n";
}
