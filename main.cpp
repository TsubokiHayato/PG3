#include <iostream>
#include <list>

struct Station
{
    const char* name;
    int year;
};

// 山手線の駅リストを作成（英語表記）
std::list<Station> createStationList() {
    std::list<Station> stations = {
        {"Tokyo", 1883}, {"Kanda", 1919}, {"Akihabara", 1925}, {"Okachimachi", 1925}, {"Ueno", 1883},
        {"Uguisudani", 1912}, {"Nippori", 1905}, {"Tabata", 1896}, {"Komagome", 1910}, {"Sugamo", 1903},
        {"Otsuka", 1903}, {"Ikebukuro", 1903}, {"Mejiro", 1885}, {"Takadanobaba", 1910}, {"Shin-Okubo", 1914},
        {"Shinjuku", 1885}, {"Yoyogi", 1906}, {"Harajuku", 1906}, {"Shibuya", 1885}, {"Ebisu", 1906},
        {"Meguro", 1909}, {"Gotanda", 1911}, {"Osaki", 1901}, {"Shinagawa", 1872}, {"Tamachi", 1909},
        {"Hamamatsucho", 1909}, {"Shimbashi", 1872}, {"Yurakucho", 1910}
    };

    // 1971年開業の西日暮里を適切な位置に挿入
    auto it = stations.begin();
    for (; it != stations.end(); ++it) {
        if (std::string(it->name) == "Nippori") {
            ++it; // 日暮里の次に挿入
            break;
        }
    }
    stations.insert(it, { "Nishi-Nippori", 1971 });

    // 2022年開業の高輪ゲートウェイを適切な位置に挿入
    it = stations.begin();
    for (; it != stations.end(); ++it) {
        if (std::string(it->name) == "Shinagawa") {
            ++it; // 品川の次に挿入
            break;
        }
    }
    stations.insert(it, { "Takanawa Gateway", 2022 });

    return stations;
}

// 指定された年代の駅を表示
void printStationsByDecade(const std::list<Station>& stations, int startYear, int endYear, const char* decadeLabel) {
    std::cout << decadeLabel << ":\n";
    for (const auto& station : stations) {
        if (station.year >= startYear && station.year < endYear) {
            std::cout << station.name << " (" << station.year << ")\n";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::list<Station> stations = createStationList();

    printStationsByDecade(stations, 1970, 1980, "Stations in 1970s");
    printStationsByDecade(stations, 2010, 2020, "Stations in 2019s");
    printStationsByDecade(stations, 2020, 2030, "Stations in 2020s");

    return 0;
}
