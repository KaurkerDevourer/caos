#include <iostream>
#include <thread>

constexpr uint64_t N = 1'000'000'000;

struct AlignedSum {
    alignas(64) uint64_t partial_sum = 0;
};

AlignedSum sum1, sum2;

void sum_range(uint64_t start, uint64_t end, AlignedSum& s) {
    for (uint64_t i = start; i <= end; ++i) {
        s.partial_sum += i;
    }
}

int main() {
    std::thread t1(sum_range, 1, N / 2, std::ref(sum1));
    std::thread t2(sum_range, N / 2 + 1, N, std::ref(sum2));

    t1.join();
    t2.join();

    uint64_t total = sum1.partial_sum + sum2.partial_sum;
    std::cout << "Sum: " << total << std::endl;
    return 0;
}
