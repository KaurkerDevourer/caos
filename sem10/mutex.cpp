#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

long long counter = 0;
std::mutex mtx;

void increment() {
    for (int i = 0; i < 100000; ++i) {
        std::lock_guard<std::mutex> guard(mtx);
        counter++;
    }
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(increment);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Ожидаемый результат: " << 10 * 100000 << std::endl;
    std::cout << "Фактический результат: " << counter << std::endl;

    return 0;
}
