#include <iostream>
#include <thread>

constexpr uint64_t N = 1'000'000'000;
uint64_t sum = 0;

void sum_range(uint64_t start, uint64_t end) {
    for (uint64_t i = start; i <= end; ++i) {
        sum += i;
    }
}

int main() {
    sum_range(1, N);

    std::cout << "Sum: " << sum << std::endl;
    return 0;
}
