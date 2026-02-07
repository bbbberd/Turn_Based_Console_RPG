#include "GameWinState.h"
#include "../core/GameManager.h"
#include "MenuState.h"
#include <iostream>

void GameWinState::Enter() {
    std::cout << "\n=== YOU WIN ===\n";
    std::cout << "[r] Restart\n";
    std::cout << "[q] Quit\n";
    std::cout << "> ";
}

void GameWinState::Update() {
    char input;
    std::cin >> input;

    if (input == 'r') {
        static MenuState menu;
        GameManager::GetInstance().stateMachine.ChangeState(&menu);
    }
    else if (input == 'q') {
        exit(0);
    }
}

void GameWinState::Exit() {}
