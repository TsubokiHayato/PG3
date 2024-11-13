#include <iostream>

class Enemy {
public:
    // コンストラクタで初期状態を設定
    Enemy();

    // 状態遷移を行う関数
    void Update();

private:
    // 各状態を表す関数
    void Approach();
    void Shoot();
    void Retreat();

    // メンバ関数ポインタ
    void (Enemy::* currentState)();
};
