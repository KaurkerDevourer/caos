#include <iostream>
#include <thread>
#include <mutex>

int global_counter = 0;
std::mutex global_mtx;

thread_local int thread_local_counter;

void worker_function(int x) {
    thread_local_counter = x;
    ++thread_local_counter;

    {
        std::lock_guard<std::mutex> guard(global_mtx);
        ++global_counter;
    }

    std::cout << "Поток ID=" << std::this_thread::get_id()
              << ", thread_local_counter = " << thread_local_counter
              << ", global_counter = " << global_counter << std::endl;
}

int main() {
    std::thread t1(worker_function, 4);
    std::thread t2(worker_function, 3);
    t1.join();
    t2.join();

    std::cout << "--- Запускаем еще раз ---" << std::endl;

    std::thread t3(worker_function, 2);
    std::thread t4(worker_function, 1);
    t3.join();
    t4.join();

    return 0;
}
