#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <iostream>

template<typename T>
class ThreadSafeQueue {
public:
    void push(T value) {
        std::unique_lock<std::mutex> lock(mtx);
        q.push(value);
        cv.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]() {
            return !q.empty();
        });
        T val = q.front();
        q.pop();
        return val;
    }

private:
    std::condition_variable cv;
    std::mutex mtx;
    std::queue<T> q;
};

void producer(ThreadSafeQueue<int>& q) {
    for (int i = 0; i < 5; ++i) {
        q.push(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer(ThreadSafeQueue<int>& q) {
    for (int i = 0; i < 5; ++i) {
        int val = q.pop();
        std::cout << "Got: " << val << std::endl;
    }
}

int main() {
    ThreadSafeQueue<int> q;
    std::thread t1(producer, std::ref(q));
    std::thread t2(consumer, std::ref(q));
    
    t1.join();
    t2.join();
}
