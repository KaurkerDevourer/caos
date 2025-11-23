#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

std::atomic<long long> atomic_counter;

void atomic_increment() {
    for (int i = 0; i < 100000; ++i) {
        atomic_counter++;
    }
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(atomic_increment);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Ожидаемый результат: " << 10 * 100000 << std::endl;
    std::cout << "Фактический результат: " << atomic_counter.load() << std::endl;

    return 0;
}
