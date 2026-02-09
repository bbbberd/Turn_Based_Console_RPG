#pragma once
#include <iostream>

class GameState {// Base class untuk semua state
protected:
    GameState* parent = nullptr;// POINTER ke parent state

public:
    virtual ~GameState() = default;// Destructor virtual -> penting untuk polymorphism
    void SetParent(GameState* p) { parent = p; }// Set parent state

    // PURE VIRTUAL FUNCTION
    // Artinya: class turunan WAJIB override
    virtual void Enter() = 0;// Dipanggil saat masuk state
    virtual void Update() = 0;// Dipanggil setiap frame/loop
    virtual void Exit() = 0;// Dipanggil saat keluar state
};