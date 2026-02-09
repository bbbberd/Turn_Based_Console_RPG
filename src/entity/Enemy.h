#pragma once
#include "Entity.h"
#include <iostream>

class Player;// forward declaration
// artinya: "Player itu ada, tapi detailnya nanti"

class Enemy : public Entity {
private:
    int hp = 3; // HP disimpan di object Enemy

public:
    void Reset() {
        hp = 3; //default HP enemy
    }

    void Update() override { // menggantikan/mendahului fungsi virtual base
        std::cout << "Musuh berfikir...\n";
    }

    void TakeDamage() {
        hp--; //kurangi 1
        std::cout << "Musuh terkena serangan! HP musuh: " << hp << "\n";
    }

    bool IsDead() const {
        return hp <= 0; // const = fungsi ini tidak mengubah object
    }

    void TryAttack(Player& player);// Player& = reference ke Player ASLI
};
