#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int turn = 1;

void printThread(int id, int next_turn) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [id] { return turn == id; });
    std::cout << "thread" << id << std::endl;
    turn = next_turn;
    cv.notify_all();
}

int main() {
    std::thread t1(printThread, 1, 2);
    std::thread t2(printThread, 2, 3);
    std::thread t3(printThread, 3, 1);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
