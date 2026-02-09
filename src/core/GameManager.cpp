#include "GameManager.h"// Ambil deklarasi GameManager
#include "../states/MenuState.h"// Game mulai dari Menu

GameManager* GameManager::instance = nullptr;
// Inisialisasi pointer singleton dengan null (belum ada instance)

GameManager& GameManager::GetInstance() {
    if (!instance) // Jika instance belum ada

        instance = new GameManager();// new -> buat object di HEAP
        // instance menyimpan ALAMAT object tersebut

    return *instance;// Dikembalikan sebagai REFERENCE karena function bertipe &
}

void GameManager::Run() {
    MenuState menu;// Membuat object MenuState di STACK

    stateMachine.ChangeState(&menu);// Mengirim ALAMAT menu ke StateMachine
    // Beritahu state machine untuk pindah ke Menu

    while (true) { // Game loop utama

        stateMachine.Update();// Update state aktif
    }
}
