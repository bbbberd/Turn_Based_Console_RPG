#pragma once
#include "../core/GameState.h"
#include "../core/GameManager.h"
#include "PlayingState.h"

class PlayingState;

class MenuState : public GameState {
public:
    void Enter() override {
        std::cout << "=== MENU ===\nTekan p untuk Play\n";
    }

    void Update() override {
        char input;
        std::cin >> input;
        if (input == 'p') {
            static PlayingState play;
            GameManager::GetInstance().stateMachine.ChangeState(&play);
        }
    }

    void Exit() override {
        std::cout << "Keluar Menu\n";
    }
};
