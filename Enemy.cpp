#include "Enemy.h"

// コンストラクタで初期状態を設定
Enemy::Enemy() : currentState(&Enemy::Approach) {}

// 状態遷移を行う関数
void Enemy::Update() {
    // メンバ関数ポインタを使って現在の状態関数を呼び出す
    (this->*currentState)();
}

// 各状態を表す関数
void Enemy::Approach() {
    std::cout << "敵が接近しています。" << std::endl;
    // 次の状態に遷移
    currentState = &Enemy::Shoot;
}

void Enemy::Shoot() {
    std::cout << "敵が射撃しています。" << std::endl;
    // 次の状態に遷移
    currentState = &Enemy::Retreat;
}

void Enemy::Retreat() {
    std::cout << "敵が離脱しています。" << std::endl;
    // 初期状態に戻す
    currentState = &Enemy::Approach;
}
