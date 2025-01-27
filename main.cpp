#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

// グローバル変数と同期用オブジェクト
std::mutex mtx;
std::condition_variable cv;
bool data_ready = false;
std::vector<std::vector<int>> map_data;

// CSVファイルを読み込む関数
void loadCSV(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::vector<std::vector<int>> temp_data;

    // ファイルを1行ずつ読み込む
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string value;
        std::vector<int> row;

        // 行をカンマで区切って数値に変換
        while (std::getline(ss, value, ',')) {
            row.push_back(std::stoi(value));
        }
        temp_data.push_back(row);
    }

    // 読み込んだデータをグローバル変数にコピーし、データ準備完了を通知
    {
        std::lock_guard<std::mutex> lock(mtx);
        map_data = temp_data;
        data_ready = true;
    }
    cv.notify_all();
}

// マップデータを表示する関数
void displayMap() {
    std::unique_lock<std::mutex> lock(mtx);
    // データが準備できるまで待機
    cv.wait(lock, [] { return data_ready; });

    // マップデータを表示
    for (const auto& row : map_data) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // CSV読み込みスレッドと表示スレッドを作成
    std::thread loader(loadCSV, "map.csv");
    std::thread displayer(displayMap);

    // スレッドの終了を待機
    loader.join();
    displayer.join();

    return 0;
}
