#pragma once
#include "GameState.h"

class StateMachine {
private:
    GameState* current = nullptr;
    GameState* next = nullptr;

public:
    void ChangeState(GameState* state) {
        next = state;
    }

    void Update() {
        if (next) {
            if (current)
                current->Exit();

            current = next;
            next = nullptr;

            if (current)
                current->Enter();
        }

        if (current)
            current->Update();
    }
};
