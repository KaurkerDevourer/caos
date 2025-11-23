#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

std::queue<int> data_queue;
std::mutex mtx;
std::condition_variable cv;
bool finished = false;

void producer() {
    for (int i = 0; i < 20; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        {
            std::lock_guard<std::mutex> guard(mtx);
            std::cout << "Producer добавляет " << i << std::endl;
            data_queue.push(i);
        }
        cv.notify_one();
    }
    {
        std::lock_guard<std::mutex> guard(mtx);
        finished = true;
    }
    cv.notify_all();
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return !data_queue.empty() || finished; });

        if (!data_queue.empty()) {
            int data = data_queue.front();
            data_queue.pop();
            lock.unlock();
            std::cout << "Consumer забирает " << data << std::endl;
        } else if (finished) {
            break;
        }
    }
}

int main() {
    std::thread p(producer);
    std::thread c1(consumer);
    std::thread c2(consumer);

    p.join();
    c1.join();
    c2.join();

    return 0;
}
