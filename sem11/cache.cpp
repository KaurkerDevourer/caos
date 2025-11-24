#include <iostream>
#include <unordered_map>
#include <mutex>
#include <thread>
#include <chrono>

thread_local std::unordered_map<int, double> MAP;
// std::unordered_map<int, double> global;
std::mutex mtx;

double heavy_math(int x) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return x * 3.14;
}

double cached_heavy_math(int x) {
    auto it = MAP.find(x);
    if (it != MAP.end()) {
        return it->second;
    }
    // {
    //     std::unique_lock<std::mutex> lock(mtx);
    //     auto it2 = global.find(x);
    //     if (it2 != global.end()) {
    //         return it2->second;
    //     }
    // }
    double result = heavy_math(x);
    MAP[x] = result;
    // {
    //     std::unique_lock<std::mutex> lock(mtx);
    //     global[x] = result;
    // }
    return result;
}

void worker(int x) {
    for (size_t i = 0; i < 3; i++) {
        double val = cached_heavy_math(x);
        std::cout << "Thread " << std::this_thread::get_id() 
                << ": heavy_math(" << x << ") = " << val << std::endl;
    }
}

int main() {
    std::thread t1(worker, 1);
    std::thread t2(worker, 1);
    std::thread t3(worker, 2);
    
    t1.join(); t2.join(); t3.join();
}
