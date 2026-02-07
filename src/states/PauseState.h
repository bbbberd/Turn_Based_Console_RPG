#pragma once
#include "../core/GameState.h"

class PauseState : public GameState {
public:
    void Enter() override {
        std::cout << "Game Paused\n";
    }

    void Update() override {}

    void Exit() override {
        std::cout << "Resume Game\n";
    }
};
