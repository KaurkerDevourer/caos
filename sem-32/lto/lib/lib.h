#include <iostream>

struct Base {
    virtual void foo() = 0;
    virtual ~Base() = default;
};

struct Derived : Base {
    void foo() override { std::cout << "Derived::foo\n"; }
};

void call_virtual(Base* b);
void call_external();
