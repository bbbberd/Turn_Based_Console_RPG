#pragma once
#include "Command.h"
#include "../entity/Player.h"

class DefendCommand : public Command {
private:
    Player& player;

public:
    explicit DefendCommand(Player& p) : player(p) {}

    void Execute() override {
        player.Defend();
    }
};
