#include<stdio.h>

// テンプレート関数
template <typename T1, typename T2>
T1 min(T1 a, T2 b) {
    if (a > b) {
        return static_cast<T1>(b); // 型の違いを考慮してキャスト
    }
    else {
        return a;
    }
}

// char 型の特殊化
template <>
char min<char>(char a, char b) {
  
    return printf("数字以外は代入できません\n");; // 代入できないので0を返す（エラーハンドリング）
}

int main() {
    int a = 8;
    int b = 10;
    float c = 1.14f;
    float d = 5.14f;
    double e = 3.64364;
    double f = 1.14514;

    // charは1文字のみ
    char g = 'A';
    char h = 'B';

    // 各型の最小値を出力
    printf("%d\n", min(a, b));          // intの比較
    printf("%f\n", min(c, d));        // floatの比較
    printf("%.6f\n", min(e, f));        // doubleの比較
    printf("%c\n", min(g, h));          // charの比較（特殊化関数）

    return 0;
}