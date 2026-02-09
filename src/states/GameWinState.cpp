#include "GameWinState.h"//include header milik class GameWinState
#include "../core/GameManager.h"//untuk mengakses StateMachine
#include "MenuState.h"//saat restart kita akan kembali ke menu
#include <iostream>

void GameWinState::Enter() {
    // Fungsi ini dipanggil SATU KALI saat state GameWin pertama aktif
    std::cout << "\n=== YOU WIN ===\n";
    std::cout << "[r] Restart\n";
    std::cout << "[q] Quit\n";
    std::cout << "> ";
}

void GameWinState::Update() {// Fungsi ini dipanggil setiap loop game
    // Selama GameWinState masih menjadi state aktif
    
    char input;// bertipe char (1 karakter)
    std::cin >> input;
    // Membaca input dari keyboard dan menyimpannya ke variabel input

    if (input == 'r') {// Jika user menekan tombol r (restart)

        static MenuState menu;
        // Membuat object MenuState
        // static artinya:
        // - object hanya dibuat SATU KALI
        // - object hidup sampai program selesai
        // Ini penting supaya pointer ke state tetap valid

        GameManager::GetInstance().stateMachine.ChangeState(&menu);
        // Mengambil instance GameManager (singleton)
        // Mengakses stateMachine
        // Meminta pindah state ke MenuState
        // &menu artinya kita mengirim ALAMAT MEMORY object menu
    }
    else if (input == 'q') {
        // Jika user menekan tombol q (quit)

        exit(0);// Menghentikan program secara langsung
        // Angka 0 artinya program berhenti tanpa error
    }
}

void GameWinState::Exit() {}// Fungsi ini dipanggil saat keluar dari GameWinState
// Saat ini kosong karena tidak ada cleanup khusus
