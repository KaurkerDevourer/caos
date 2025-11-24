#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

template<typename T, typename Func>
void parallel_transform(std::vector<T>& data, Func func, size_t num_threads) {
    size_t n = data.size();
    num_threads = std::min(num_threads, n);
    size_t len = (n + num_threads - 1) / num_threads;

    auto worker = [&](size_t l, size_t r) {
        for (size_t i = l; i < r; ++i) {
            data[i] = func(data[i]);
        }
    };

    std::vector<std::thread> thread(num_threads);
    for (size_t i = 0; i < num_threads; ++i) {
        size_t l = i * len;
        size_t r = std::min(n, l + len);
        thread[i] = std::thread(worker, l, r);
    }

    for (size_t i = 0; i < num_threads; ++i) {
        thread[i].join();
    }
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    parallel_transform(vec, [](int x) { 
        return x * 2; 
    }, 4);

    for (int x : vec) {
        std::cout << x << " ";
    }
}
