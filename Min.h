#pragma once

// クラステンプレートの定義
template <typename T1, typename T2>
class Min {
public:
    T1 a;
    T2 b;

    // コンストラクタ: 2つの引数を初期化
    Min(T1 val1, T2 val2) : a(val1), b(val2) {}

    // Min関数: 2つの引数のうち小さい値を返す
    auto GetMin() const {
        if (a < b) {
            return static_cast<T1>(a); // 明示的にT1にキャスト
        }
        else {
            return static_cast<T1>(b); // 明示的にT1にキャスト
        }
    }
};
