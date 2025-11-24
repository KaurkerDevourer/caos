#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::mutex mtx;
bool c;
std::condition_variable cv;

void ping(size_t count) {
    for (size_t i = 0; i < count; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait_for(lock, std::chrono::seconds(1), [](){
            return !c;
        });
        std::cout << "ping" << std::endl;
        c = true;
        // cv.notify_one();
    }
}

void pong(size_t count) {
    for (size_t i = 0; i < count; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait_for(lock, std::chrono::seconds(1), [](){
            return c;
        });
        std::cout << "pong" << std::endl;
        c = false;
        // cv.notify_one();
    }
}

int main() {
    size_t count = 10;

    std::thread t1(ping, count);
    std::thread t2(pong, count);
    
    t1.join();
    t2.join();
}
