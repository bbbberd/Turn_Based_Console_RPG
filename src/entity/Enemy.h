#pragma once
#include "Entity.h"
#include <iostream>

class Player;

class Enemy : public Entity {
private:
    int hp = 3;

public:
    void Reset() {
        hp = 3;
    }

    void Update() override {
        std::cout << "Musuh berfikir...\n";
    }

    void TakeDamage() {
        hp--;
        std::cout << "Musuh terkena serangan! HP musuh: " << hp << "\n";
    }

    bool IsDead() const {
        return hp <= 0;
    }

    void TryAttack(Player& player);
};
