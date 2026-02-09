// Memasukkan deklarasi GameManager
// dari folder core
#include "core/GameManager.h"

// Titik masuk program C++
int main() {
    GameManager::GetInstance().Run();// GameManager adalah singleton (hanya boleh ada 1).
    // GetInstance() mengembalikan referensi ke instance tersebut.
    // Run() menjalankan loop utama game.

    return 0;// Mengembalikan 0 ke OS
    // artinya program berhenti
}
