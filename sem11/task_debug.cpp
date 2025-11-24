#include "trololo.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <atomic>
#include <mutex>

std::mutex mtx;
std::atomic<int> shared_counter = {0};

void worker(int id) {
    for (int i = 0; i < 5; ++i) {
        {
            // mtx.lock();

            std::cout << secret << std::endl;
            // mtx.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

int main() {
    const int num_threads = 3;
    std::vector<std::thread> threads;
    
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(worker, i + 1);
    }
    
    for (auto& t : threads) {
        t.join();
    }
    
    std::cout << "Final counter value: " << shared_counter << std::endl;
}
