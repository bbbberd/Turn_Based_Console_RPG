#pragma once
#include "Command.h"// agar AttackCommand tahu apa itu Command
#include "../entity/Enemy.h"// agar tahu class Enemy
#include <iostream>// untuk std::cout

class AttackCommand : public Command {// AttackCommand adalah turunan dari Command
// Bisa diperlakukan sebagai Command* atau Command& (polymorphism)
private:
    Enemy& enemy;//enemy REFERENCE ke Enemy (&)
    // BUKAN copy

public:
    explicit AttackCommand(Enemy& e) : enemy(e) {}// Constructor
    // explicit -> mencegah implicit conversion
    // Enemy& e = reference ke musuh yang AKTIF
    // enemy sekarang alias ke e

    void Execute() override { // override = fungsi ini menggantikan fungsi virtual base class
        std::cout << "Player menyerang musuh!\n";
        enemy.TakeDamage();// Memanggil fungsi Enemy ASLI
    }
};
