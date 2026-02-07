#include "GameManager.h"
#include "../states/MenuState.h"

GameManager* GameManager::instance = nullptr;

GameManager& GameManager::GetInstance() {
    if (!instance)
        instance = new GameManager();
    return *instance;
}

void GameManager::Run() {
    MenuState menu;
    stateMachine.ChangeState(&menu);

    while (true) {
        stateMachine.Update();
    }
}
