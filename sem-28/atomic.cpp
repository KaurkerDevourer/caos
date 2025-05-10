#include <atomic>
#include <iostream>
#include <thread>

constexpr uint64_t N = 10'000'000;
std::atomic<uint64_t> sum{0};

void sum_range(uint64_t start, uint64_t end) {
    for (uint64_t i = start; i <= end; ++i) {
        sum.fetch_add(i);
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
t1     |   t2
x = 0;    y = 0;
y = 1;    x = 1;


(x, y) ?

(1, 0)
(0, 1)
(1, 1)

[0, 0]
*/
