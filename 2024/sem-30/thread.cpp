#include <thread>

int main() {
    int x;
    std::thread t([&]{x = 42;});
    x = 43;
    t.join();
}
