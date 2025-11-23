#include <iostream>
#include <vector>
#include <thread>
#include <fstream>
#include <string>
#include <atomic>
#include <numeric>
#include <stdexcept>
#include <chrono>

std::atomic<long long> atomicSum = {0};

long long easy_sum(const std::vector<int>& numbers) {
    long long sum = 0;
    for (size_t i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
    }
    return sum;
}

void calc_sum(int l, int r, const std::vector<int> &a) {
    long long cur_sum = 0;
    for (int i = l ; i < r; ++i) {
        cur_sum += a[i];
    }
    atomicSum += cur_sum;
}

long long get_sum(const std::vector<int> &a, int thread_cnt) {
    atomicSum = 0;
    int chunk = (int)(a.size() + thread_cnt - 1) / thread_cnt;
    std::vector<std::thread> threads;    
    for (int cnt = 0; cnt < thread_cnt; ++cnt) {
        int l = cnt * chunk, r = std::min((int)a.size(), l + chunk);
        threads.emplace_back(calc_sum, l, r, a);
    }

    auto start_time = std::chrono::high_resolution_clock::now();
    for (auto &t : threads) {
        t.join();
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "atomic sum: " << duration.count() << " ms" << std::endl;
    return atomicSum;
}

void calc_sum2(int l, int r, const std::vector<int> &a, long long& sum) {
    for (int i = l ; i < r; ++i) {
        sum += a[i];
    }
}

long long get_sum2(const std::vector<int> &a, int thread_cnt) {
    int chunk = (int)(a.size() + thread_cnt - 1) / thread_cnt;
    std::vector<std::thread> threads;    
    std::vector<long long> partialSums(thread_cnt);
    for (int cnt = 0; cnt < thread_cnt; ++cnt) {
        int l = cnt * chunk, r = std::min((int)a.size(), l + chunk);
        threads.emplace_back(calc_sum2, l, r, a, std::ref(partialSums[cnt]));
    }
    
    auto start_time = std::chrono::high_resolution_clock::now();
    for (auto &t : threads) {
        t.join();
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Partial sum: " << duration.count() << " ms" << std::endl;
    long long totalSum = 0;
    for (long long& sums : partialSums) {
        totalSum += sums;
    }
    return totalSum;
}

struct LongLongAligned {
    alignas(64) long long X;
};

void calc_sum3(int l, int r, const std::vector<int> &a, long long& sum) {
    for (int i = l ; i < r; ++i) {
        sum += a[i];
    }
}

long long get_sum3(const std::vector<int> &a, int thread_cnt) {
    int chunk = (int)(a.size() + thread_cnt - 1) / thread_cnt;
    std::vector<std::thread> threads;    
    std::vector<LongLongAligned> partialSums(thread_cnt);
    for (int cnt = 0; cnt < thread_cnt; ++cnt) {
        int l = cnt * chunk, r = std::min((int)a.size(), l + chunk);
        threads.emplace_back(calc_sum3, l, r, a, std::ref(partialSums[cnt].X));
    }
    
    auto start_time = std::chrono::high_resolution_clock::now();
    for (auto &t : threads) {
        t.join();
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Aligned sum: " << duration.count() << " ms" << std::endl;
    long long totalSum = 0;
    for (auto& sums : partialSums) {
        totalSum += sums.X;
    }
    return totalSum;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Использование: " << argv[0] << " <имя_файла> <количество_потоков>\n";
        return 1;
    }

    const std::string filename = argv[1];
    int num_threads = std::stoi(argv[2]);

    std::ifstream file(filename);
    int n;
    file >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        file >> numbers[i];
    }


    {
        auto start_time = std::chrono::high_resolution_clock::now();
        long long ans = easy_sum(numbers);
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        std::cout << "Sum: " << ans << std::endl;
        std::cout << "easy_sum: " << duration.count() << " ms" << std::endl;
    }

    {
        long long ans = get_sum(numbers, num_threads);
        std::cout << "Sum: " << ans << std::endl;
    }

    {
        long long ans = get_sum2(numbers, num_threads);
        std::cout << "Sum: " << ans << std::endl;
    }

    {
        long long ans = get_sum3(numbers, num_threads);
        std::cout << "Sum: " << ans << std::endl;
    }
}
