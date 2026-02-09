#include "GameOverState.h"//include header milik class GameOverState
//Enter, Update, Exit
#include "../core/GameManager.h"//StateMachine untuk pindah state
#include "MenuState.h"//restart kita akan kembali ke menu
#include <iostream>

void GameOverState::Enter() {// Fungsi ini dipanggil  
    //saat state GameOver pertama kali aktif
    std::cout << "\n=== GAME OVER ===\n";
    std::cout << "[r] Restart\n";
    std::cout << "[q] Quit\n";
    std::cout << "> ";
}

void GameOverState::Update() {// Fungsi dipanggil setiap loop game 
    //selama state GameOver aktif
    char input;
    std::cin >> input;// Membaca input dari keyboard

    if (input == 'r') {// Jika user menekan huruf r
        static MenuState menu;// Membuat object MenuState
        // static artinya object ini dibuat sekali dan tetap hidup selamanya
        // Tujuannya supaya pointer ke state tetap valid

        GameManager::GetInstance().stateMachine.ChangeState(&menu);
        // Mengambil singleton GameManager
        // Mengakses StateMachine
        // Meminta pindah state ke MenuState
        // &menu artinya mengirim alamat memory dari object menu (pointer)
    }
    else if (input == 'q') {// Jika user menekan huruf q
        exit(0);// Menghentikan program langsung
        // 0 artinya program selesai tanpa error
    }
}

void GameOverState::Exit() {}// Fungsi dipanggil saat keluar dari GameOverState
// Saat ini kosong (tidak melakukan apa-apa)
