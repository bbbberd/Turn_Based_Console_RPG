#pragma once
#include "Command.h"
#include <iostream>

class MoveCommand : public Command {// MoveCommand adalah turunan dari Command
// Bisa diperlakukan sebagai Command* atau Command& (polymorphism)
public:
    void Execute() override { //menimpa fungsi virtual
        std::cout << "Player maju\n"; // command ini tidak mempengaruhi data apa pun
    }
};
