#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

// グローバル変数と同期用オブジェクト
std::mutex mtx;
std::condition_variable cv;
int turn = 1;

// スレッド関数
void printThread(int id, int next_turn) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [id] { return turn == id; }); // 自分のターンを待つ
    std::cout << "thread" << id << std::endl; // スレッドIDを出力
    turn = next_turn; // 次のターンを設定
    cv.notify_all(); // 他のスレッドに通知
}

int main() {
    // スレッドの作成
    std::thread t1(printThread, 1, 2);
    std::thread t2(printThread, 2, 3);
    std::thread t3(printThread, 3, 1);

    // スレッドの終了を待つ
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
