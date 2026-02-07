#include "Enemy.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>

void Enemy::TryAttack(Player& player) {
    int roll = rand() % 2;

    if (roll == 1) {
        std::cout << "Musuh menyerang!\n";
        player.TakeDamage();
    }
    else {
        std::cout << "Musuh bingung dan tidak melakukan apapun.\n";
    }
}
