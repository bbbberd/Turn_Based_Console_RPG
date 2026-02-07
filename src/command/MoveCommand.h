#pragma once
#include "Command.h"
#include <iostream>

class MoveCommand : public Command {
public:
    void Execute() override {
        std::cout << "Player maju\n";
    }
};
