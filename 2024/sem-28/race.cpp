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
    std::thread t1(sum_range, 1, N / 2);
    std::thread t2(sum_range, N / 2 + 1, N);

    t1.join();
    t2.join();

    std::cout << "Sum: " << sum << std::endl;
    return 0;
}

/*
t1 | t2

+= -> 0 [get(sum), add(sum)] 1

0 | 0
1 | 2
3


*/
