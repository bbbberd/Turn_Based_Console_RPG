#pragma once
#include "Entity.h"
#include "../observer/Subject.h"
#include <iostream>

class Player : public Entity, public Subject {
private:
    int hp = 5;
    bool isDefending = false;

public:
    void Defend() {
        isDefending = true;
        std::cout << "Player defending!\n";
    }

    void Reset() {
        hp = 5;
        isDefending = false;
    }

    void TakeDamage() {
        if (isDefending) {
            std::cout << "Damage ditahan!\n";
            isDefending = false; // defense only 1 turn
            return;
        }

        hp--;
        if (hp < 0) hp = 0;
        std::cout << "Player HP: " << hp << "\n";

        if (hp <= 0) {
            Notify("PlayerMati");
        }
    }

    void Update() override {}
};
