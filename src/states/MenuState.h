#pragma once
#include "../core/GameState.h"
#include "../core/GameManager.h"
#include "PlayingState.h"

class PlayingState;// Forward declaration

class MenuState : public GameState {
public:
    void Enter() override {
        std::cout << "=== MENU ===\nTekan p untuk Play\n";
        // Saat masuk menu, tampilkan teks
    }

    void Update() override {
        char input;// Variable untuk menyimpan input keyboard
        std::cin >> input;// Ambil input user
        if (input == 'p') {// Jika tekan p
            static PlayingState play;// Buat PlayingState static (tidak hilang)
            GameManager::GetInstance().stateMachine.ChangeState(&play);
            // Pindah ke state bermain
        }
    }

    void Exit() override {
        std::cout << "Keluar Menu\n";// Saat keluar menu
    }
};
