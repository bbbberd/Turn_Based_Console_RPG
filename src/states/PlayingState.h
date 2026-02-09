#pragma once// mencegah redefinition
#include "../core/GameState.h" //PlayingState adalah turunan dari GameState
#include "../core/GameManager.h"// Supaya bisa pindah ke GameOver atau GameWin

#include "../command/MoveCommand.h"
#include "../command/AttackCommand.h"
#include "../command/DefendCommand.h"
// Command pattern:
// Input pemain akan diubah menjadi object Command

#include "../entity/Player.h"// PlayingState memiliki object Player
#include "../entity/Enemy.h"// PlayingState memiliki object Enemy
// Class entity gameplay utama

#include "../pool/ObjectPool.h"
// Sistem object pool untuk Enemy
// Supaya tidak sering new/delete (hemat CPU spike)

#include "GameOverState.h"
#include "GameWinState.h"
// State tujuan ketika kalah / menang

#include <cstdlib>// Untuk fungsi exit()
#include <ctime>// Untuk time() sebagai seed random

class PlayingState : public GameState, public Observer {
    // GameState (untuk StateMachine)
    // Observer (mendengar event dari Player)
private:
    Player player;// Object Player disimpan langsung (bukan pointer)
    // Artinya Player hidup selama PlayingState hidup

    ObjectPool<Enemy> enemyPool;// Pool untuk reuse Enemy
    Enemy* currentEnemy = nullptr;// Musuh aktif
    bool firstTurn = true;// Penanda apakah ini turn pertama
    bool isStateChanging = false;// Proteksi saat pindah state

public:
    void Enter() override {// Dipanggil saat masuk PlayingState
        std::cout << "\n=== MULAI ===\n";
        std::cout << "[w] Move  [a] Attack  [d] Defend  [q] Quit\n>";

        player.Reset();// Reset HP player
        player.AddObserver(this);// PlayingState mendaftarkan diri sbg observer
        // Jika player mati ? PlayingState akan diberi notifikasi

        srand(static_cast<unsigned>(time(nullptr))); // Seed random
        // Supaya hasil random tidak selalu sama

        firstTurn = true;// Set ulang ke turn pertama

        currentEnemy = enemyPool.GetObject();// Meminta 1 enemy dari pool
        // Bisa:
        // - mengambil enemy bekas
        // - atau membuat baru jika pool kosong

        currentEnemy->Reset();// Reset HP enemy
    }


    void Update() override// Dipanggil setiap loop game
    {
        if (isStateChanging) return;// Jika sedang pindah state, stop
        if (!firstTurn)
        {
            std::cout << "\n----- NEXT TURN -----\n";
            std::cout << "[w] Move  [a] Attack  [d] Defend  [q] Quit\n";
            std::cout << "> " << std::flush;
        }
        firstTurn = false;// Setelah loop pertama, bukan turn pertama lagi

        char input;
        std::cin >> input;// Input player

        Command* cmd = nullptr;// Pointer ke command

        if (input == 'w') cmd = new MoveCommand();// Jika w ? buat MoveCommand
        else if (input == 'a') cmd = new AttackCommand(*currentEnemy);// Jika a ? buat AttackCommand
        else if (input == 'd') cmd = new DefendCommand(player);// Jika d ? buat DefendCommand
        else if (input == 'q') exit(0);// Keluar program langsung

        if (cmd) {// Jika command berhasil dibuat
            cmd->Execute();// Jalankan command
            delete cmd;// Hapus nilai cmd dari heap
        }

        /* ===== CEK ENEMY MATI ===== */
        if (currentEnemy->IsDead()) {// Jika HP enemy <= 0
            std::cout << "Musuh tumbang...\n";

            enemyPool.ReturnObject(currentEnemy);// Enemy dikembalikan ke pool
            // Tidak di-delete
            currentEnemy = nullptr;// Pointer dikosongkan agar tidak dangling

            static GameWinState win;// Membuat state menang (static supaya pointer aman)

            GameManager::GetInstance().stateMachine.ChangeState(&win);
            // Minta StateMachine pindah ke GameWinState

            return;// Hentikan Update sekarang
        }

        /* ===== TURN MUSUH ===== */
        currentEnemy->Update();// Enemy thinking

        currentEnemy->TryAttack(player);// Enemy menyerang player

        if (isStateChanging) return;// Jika player mati saat diserang
        // OnNotify akan mengubah state
    }

    void Exit() override {// Dipanggil saat keluar dari PlayingState

        isStateChanging = false;// Reset flag

        std::cout << "Keluar State Play\n";
    }

    void OnNotify(const std::string& event) override {// Fungsi dari Observer
        // Dipanggil ketika Player mengirim event

        if (event == "PlayerMati") {// Jika event menyatakan player mati
            
            isStateChanging = true;// Mengunci update agar tidak lanjut logic
            static GameOverState gameOver;// Membuat state kalah (static supaya aman)
            
            GameManager::GetInstance().stateMachine.ChangeState(&gameOver);
            // Pindah ke GameOverState
        }
    }
};
