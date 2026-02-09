#pragma once //pastikan file ini hanya di-include SATU KALI
#include "Command.h"// agar tahu apa itu Command
#include "../entity/Player.h"// agar tahu apa itu Player

class DefendCommand : public Command {// DefendCommand adalah turunan dari Command
// Bisa diperlakukan sebagai Command* atau Command& (polymorphism)
private:
    Player& player;// reference ke Player asli

public:
    explicit DefendCommand(Player& p) : player(p) {}// Constructor
    // explicit -> mencegah implicit conversion
    // Player& p = reference ke player yang AKTIF
    // player sekarang alias ke p

    void Execute() override {// menggantikan fungsi virtual base class
        player.Defend();// mengubah state Player asli
    }
};
