#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <functional>

// サイコロを振る関数
int rollDice() {
    return rand() % 6 + 1;  // 1から6までのランダムな整数を生成
}

// 判定関数（奇数か偶数かを判定）
bool isEven(int num) {
    return num % 2 == 0;  // 偶数の場合はtrueを返す
}

// 結果を判定して表示するコールバック関数
void displayResult(bool correct) {
    // 結果を表示
    if (correct) {
        printf("正解!\n");
    }
    else {
        printf("不正解!\n");
    }
}

// ゲームロジックを実行する関数
void playGame(std::function<void(bool)> callback) {
    int dice = rollDice();  // ランダムにサイコロを振る
    printf("サイコロを振りました...\n");

    int userChoice;
    printf("奇数 (1) か偶数 (0) かを予想してください: ");
    scanf_s("%d", &userChoice);  // scanf_sを使用

    // 結果を判定
    bool diceIsEven = isEven(dice);
    bool correct = (userChoice == 0 && diceIsEven) || (userChoice == 1 && !diceIsEven);

    // 3秒待つ
    std::this_thread::sleep_for(std::chrono::seconds(3));  // ユーザーが答えた後に3秒待つ

    callback(correct);  // 結果をコールバックで返す
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // ランダムシードの設定

    playGame(displayResult);  // ゲームを実行し、結果を表示する

    return 0;
}
