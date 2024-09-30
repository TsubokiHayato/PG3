#include <stdio.h>

// 再雇用賃金を再帰的に計算する関数
int calculateReemploymentWage(int hoursWorked) {
    if (hoursWorked == 1) {
        return 100; // 最初の1時間目は100円
    }
    int previousWage = calculateReemploymentWage(hoursWorked - 1);
    return (previousWage * 2) - 50; // 前の時給を2倍し、50円減らす
}

int main() {
    int generalWagePerHour = 1072; // 一般賃金（1時間あたり）
    int hoursWorked = 0;  // 労働時間

    int generalTotalWage = 0;  // 一般賃金の合計
    int reemploymentTotalWage = 0;  // 再雇用賃金の合計

    // 再雇用賃金が一般賃金を超えるまで比較するループ
    while (reemploymentTotalWage <= generalTotalWage) {
        ++hoursWorked;
        generalTotalWage = hoursWorked * generalWagePerHour;

        // 再帰関数を使用して再雇用賃金を計算
        reemploymentTotalWage = calculateReemploymentWage(hoursWorked);

        // 各時間ごとの賃金比較をprintfで表示
        printf("時間 %d: 一般賃金: %d, 再雇用賃金: %d\n", hoursWorked, generalTotalWage, reemploymentTotalWage);

        // 再雇用賃金がマイナスになった場合は終了
        if (reemploymentTotalWage < 0) {
            printf("再雇用賃金が0未満になりました。計算を停止します。\n");
            break;
        }
    }

    printf("再雇用賃金が一般賃金を超えるのは %d 時間後です。\n", hoursWorked);

    return 0;
}