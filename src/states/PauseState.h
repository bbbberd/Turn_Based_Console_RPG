#pragma once// untuk mencegah error "redefinition"
#include "../core/GameState.h"//PauseState adalah "turunan" (inherit) dari GameState

class PauseState : public GameState {
public:
    void Enter() override {// Fungsi ini MENIMPA (override) fungsi virtual Enter()
    //yang didefinisikan di GameState

        std::cout << "Game Paused\n";
    }

    void Update() override {}// Dipanggil TERUS MENERUS oleh StateMachine
    // Artinya:
    // - Saat game di-pause, tidak ada input
    // - Tidak ada logika
    // - Game "membeku" secara fungsional

    void Exit() override {
        // ? Dipanggil SAAT game keluar dari PauseState
        std::cout << "Resume Game\n";
        // ? Menampilkan pesan bahwa game dilanjutkan kembali
    }
};
