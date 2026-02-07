#pragma once
#include "Command.h"
#include "../entity/Enemy.h"
#include <iostream>

class AttackCommand : public Command {
private:
    Enemy& enemy;

public:
    explicit AttackCommand(Enemy& e) : enemy(e) {}

    void Execute() override {
        std::cout << "Player menyerang musuh!\n";
        enemy.TakeDamage();
    }
};
