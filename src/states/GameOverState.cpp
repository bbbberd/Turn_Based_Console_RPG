#include "GameOverState.h"
#include "../core/GameManager.h"
#include "MenuState.h"
#include <iostream>

void GameOverState::Enter() {
    std::cout << "\n=== GAME OVER ===\n";
    std::cout << "[r] Restart\n";
    std::cout << "[q] Quit\n";
    std::cout << "> ";
}

void GameOverState::Update() {
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

void GameOverState::Exit() {}
