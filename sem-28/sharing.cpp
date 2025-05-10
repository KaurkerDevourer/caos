#include <atomic>
#include <iostream>
#include <thread>

constexpr uint64_t N = 1'000'000'000;

uint64_t sum1 = 0;
uint64_t sum2 = 0;

void sum_range(uint64_t start, uint64_t end, uint64_t& partial_sum) {
    for (uint64_t i = start; i <= end; ++i) {
        partial_sum += i;
    }
}

int main() {
    std::thread t1(sum_range, 1, N / 2, std::ref(sum1));
    std::thread t2(sum_range, N / 2 + 1, N, std::ref(sum2));

    t1.join();
    t2.join();

    uint64_t total = sum1 + sum2;
    std::cout << "Sum: " << total << std::endl;
    return 0;
}
