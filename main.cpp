#include <iostream>
#include <list>

class Station {
public:
    const char* name;
    int year;

    Station(const char* name, int year) : name(name), year(year) {}
};

int main() {
    // 1970年代の駅（開業年順に配置）
    std::list<Station> stations = {
        Station("Shinjuku", 1885),
        Station("Shibuya", 1885),
        Station("Ikebukuro", 1903),
        Station("Ueno", 1883),
        Station("Tokyo", 1914)
    };

    // 1970年代駅の後に西日暮里を追加
    auto it = stations.begin();
    for (; it != stations.end(); ++it) {
        if (it->year > 1971) {
            break;
        }
    }
    stations.insert(it, Station("Nishi-Nippori", 1971));

    // 2019年代の駅を追加
    stations.push_back(Station("Takanawa Gateway", 2022));

    // 駅名を英語表記で出力
    std::cout << "Stations in 1970s:" << std::endl;
    for (auto& station : stations) {
        if (station.year >= 1970 && station.year < 1980) {
            std::cout << station.name << " (" << station.year << ")" << std::endl;
        }
    }

    std::cout << "\nStations in 2019s:" << std::endl;
    for (auto& station : stations) {
        if (station.year >= 2010 && station.year < 2020) {
            std::cout << station.name << " (" << station.year << ")" << std::endl;
        }
    }

    std::cout << "\nStations in 2020s:" << std::endl;
    for (auto& station : stations) {
        if (station.year >= 2020) {
            std::cout << station.name << " (" << station.year << ")" << std::endl;
        }
    }

    return 0;
}
