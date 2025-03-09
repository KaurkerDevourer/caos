#include <dlfcn.h>
#include <iostream>

int main() {
    void* handle = dlopen("./libmath_utils.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Error loading library: " << dlerror() << std::endl;
        return 1;
    }

    typedef int (*add_func)(int, int);
    add_func add = (add_func)dlsym(handle, "add");
    if (!add) {
        std::cerr << "Error finding symbol: " << dlerror() << std::endl;
        dlclose(handle);
        return 1;
    }

    std::cout << "5 + 3 = " << add(5, 3) << std::endl;

    dlclose(handle);
    return 0;
}
