#pragma once
#include "StateMachine.h"

class GameManager {
private:
    static GameManager* instance;
    GameManager() = default;

public:
    StateMachine stateMachine;

    static GameManager& GetInstance();
    void Run();
};
