#pragma once
#include <iostream>

class GameState {
protected:
    GameState* parent = nullptr;

public:
    virtual ~GameState() = default;
    void SetParent(GameState* p) { parent = p; }

    virtual void Enter() = 0;
    virtual void Update() = 0;
    virtual void Exit() = 0;
};