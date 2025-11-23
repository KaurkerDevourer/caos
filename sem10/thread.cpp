#include <iostream>
#include <thread>
#include <chrono>
#include <string>

void worker(int id, int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << "Поток " << id << " выводит сообщение " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main() {
    std::cout << "Главный поток начинает работу." << std::endl;

    std::thread t1(worker, 1, 5);
    std::thread t2(worker, 2, 5);

    std::cout << "Главный поток создал дочерние потоки." << std::endl;

    t1.join();
    t2.join();

    std::cout << "Главный поток завершает работу." << std::endl;
    return 0;
}
