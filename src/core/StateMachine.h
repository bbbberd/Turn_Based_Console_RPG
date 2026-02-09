#pragma once //memastikan deklarasi dilakukan sekali
#include "GameState.h"// Base class semua state

class StateMachine {// StateMachine = pengelola pergantian state
private:
    GameState* current = nullptr;// POINTER ke state yang sedang aktif
    GameState* next = nullptr;// POINTER ke state berikutnya

public:
    void ChangeState(GameState* state) {// Menerima POINTER ke GameState
        
        next = state;// Set state berikutnya
        // Tidak langsung ganti
        // Disimpan dulu
    }

    void Update() {
        if (next) {// Jika ada state baru
            if (current)// Jika ada state lama
                current->Exit();// Panggil Exit 
                //keluar state lama

            current = next;// Pindahkan pointer
            // Ganti state aktif

            next = nullptr;// Reset next

            if (current)
                current->Enter(); // Masuk state baru
        }

        if (current)
            current->Update(); // Jalankan Update state aktif
    }
};
