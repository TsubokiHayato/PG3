#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool data_ready = false;
std::vector<std::vector<int>> map_data;

void loadCSV(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::vector<std::vector<int>> temp_data;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string value;
        std::vector<int> row;

        while (std::getline(ss, value, ',')) {
            row.push_back(std::stoi(value));
        }
        temp_data.push_back(row);
    }

    {
        std::lock_guard<std::mutex> lock(mtx);
        map_data = temp_data;
        data_ready = true;
    }
    cv.notify_all();
}

void displayMap() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return data_ready; });

    for (const auto& row : map_data) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::thread loader(loadCSV, "map.csv");
    std::thread displayer(displayMap);

    loader.join();
    displayer.join();

    return 0;
}
