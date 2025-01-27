#include <iostream>
#include <string>
#include <chrono>

int main() {
    // 100000文字の'a'で初期化されたstd::stringを作成
    std::string original(100000, 'a');

    // コピーの時間計測開始
    auto start_copy = std::chrono::high_resolution_clock::now();
    std::string copy = original; // コピー
    auto end_copy = std::chrono::high_resolution_clock::now();

    // コピーにかかった時間を計算
    auto duration_copy = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();

    // 移動の時間計測開始
    auto start_move = std::chrono::high_resolution_clock::now();
    std::string moved = std::move(original); // 移動
    auto end_move = std::chrono::high_resolution_clock::now();

    // 移動にかかった時間を計算
    auto duration_move = std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count();

    // 結果を表示
    std::cout << "コピーにかかった時間: " << duration_copy << " マイクロ秒" << std::endl;
    std::cout << "移動にかかった時間: " << duration_move << " マイクロ秒" << std::endl;

    return 0;
}
