#include <stdio.h>
// Bad things happening here. Probably best not to run this code.

void try_privileged() {
    __asm__("cli");
}

int main() {
    try_privileged();
    return 0;
}

// sudo dmesg | tail
