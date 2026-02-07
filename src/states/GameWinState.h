#pragma once
#include "../core/GameState.h"

class GameWinState : public GameState {
public:
    void Enter() override;
    void Update() override;
    void Exit() override;
};
