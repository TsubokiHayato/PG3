#include "Enemy.h"

int main() {
    Enemy enemy;

    // 状態遷移を3回実行
    for (int i = 0; i < 3; ++i) {
        enemy.Update();
    }

    return 0;
}
