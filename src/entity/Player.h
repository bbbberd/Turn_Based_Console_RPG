#pragma once //Mencegah redefinisi
#include "Entity.h"// Meng-include class Entity
#include "../observer/Subject.h"// Meng-include Subject dari Observer Pattern.
#include <iostream>

class Player : public Entity, public Subject {// class Player mewarisi 2 class:
// 1. Entity  -> supaya dianggap sebagai object game entity
// 2. Subject -> supaya bisa mengirim notifikasi event

private:
    int hp = 5; // hp = health point pemain
    // Disimpan sebagai integer

    bool isDefending = false; //status defend player

public:
    void Defend() { //fungsi jika defend dipilih
        isDefending = true;// Status defend diaktifkan
        std::cout << "Player defending!\n";
    }

    void Reset() { //fungsi reset
        hp = 5;// HP kembali penuh
        isDefending = false;// Status defend dimatikan
    }

    void TakeDamage() { //fungsi terkena damage
        if (isDefending) {// Jika sebelumnya player sedang defend
            std::cout << "Damage ditahan!\n";
            isDefending = false;// Defense hanya berlaku 1 turn
            return;// Keluar dari fungsi tanpa mengurangi HP
        }

        hp--;// Jika tidak defend ? HP dikurangi 1
        if (hp < 0) hp = 0;
        // Clamp agar HP tidak negatif

        std::cout << "Player HP: " << hp << "\n";// Tampilkan HP terbaru

        if (hp <= 0) {// Jika HP habis
            Notify("PlayerMati"); // kirim event ke observer
            // Observer bisa berupa PlayingState
            // Ini memicu perubahan state ke GameOver
        }
    }

    void Update() override {}// Override fungsi virtual dari Entity
    // Saat ini kosong (player tidak punya AI otomatis)
};
