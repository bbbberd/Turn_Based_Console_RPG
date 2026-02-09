#pragma once // Mencegah file ini di-include lebih dari sekali
#include "StateMachine.h"// Membutuhkan class StateMachine

class GameManager { // GameManager = pengontrol utama game
private:
    static GameManager* instance; // POINTER ke SATU object GameManager
    // static artinya shared milik class, bukan milik object
    
    GameManager() = default;// Constructor dibuat PRIVATE
    // Artinya: tidak boleh membuat GameManager dari luar

public:
    StateMachine stateMachine;// StateMachine adalah OBJECT, bukan pointer
    // Karena GameManager hidup lama, StateMachine juga

    static GameManager& GetInstance();// Fungsi static -> bisa dipanggil TANPA object
    // Mengembalikan REFERENCE ke GameManager

    void Run();// Memulai game loop
};
