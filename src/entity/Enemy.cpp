#include "Enemy.h"
#include "Player.h"
#include <iostream>
#include <cstdlib> // rand()

void Enemy::TryAttack(Player& player) {//reference ke player
    int roll = rand() % 2;// rand() % 2 -> hasilnya 0 atau 1

    if (roll == 1) {
        std::cout << "Musuh menyerang!\n";
        player.TakeDamage();// menyerang Player ASLI
    }
    else {
        std::cout << "Musuh bingung dan tidak melakukan apapun.\n";
    }
}
