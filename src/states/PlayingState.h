#pragma once
#include "../core/GameState.h"
#include "../core/GameManager.h"
#include "../command/MoveCommand.h"
#include "../command/AttackCommand.h"
#include "../command/DefendCommand.h"
#include "../entity/Player.h"
#include "../entity/Enemy.h"
#include "../pool/ObjectPool.h"
#include "GameOverState.h"
#include "GameWinState.h"
#include <cstdlib>
#include <ctime>

class PlayingState : public GameState, public Observer {
private:
    Player player;
    ObjectPool<Enemy> enemyPool;
    Enemy* currentEnemy = nullptr;
    bool firstTurn = true;
    bool isStateChanging = false;

public:
    void Enter() override {
        std::cout << "\n=== MULAI ===\n";
        std::cout << "[w] Move  [a] Attack  [d] Defend  [q] Quit\n>";

        player.Reset();
        player.AddObserver(this);

        srand(static_cast<unsigned>(time(nullptr)));

        firstTurn = true;

        currentEnemy = enemyPool.GetObject();
        currentEnemy->Reset();
    }


    void Update() override
    {
        if (isStateChanging) return;
        if (!firstTurn)
        {
            std::cout << "\n----- NEXT TURN -----\n";
            std::cout << "[w] Move  [a] Attack  [d] Defend  [q] Quit\n";
            std::cout << "> " << std::flush;
        }
        firstTurn = false;

        char input;
        std::cin >> input;

        Command* cmd = nullptr;

        if (input == 'w') cmd = new MoveCommand();
        else if (input == 'a') cmd = new AttackCommand(*currentEnemy);
        else if (input == 'd') cmd = new DefendCommand(player);
        else if (input == 'q') exit(0);

        if (cmd) {
            cmd->Execute();
            delete cmd;
        }

        /* ===== CEK ENEMY MATI ===== */
        if (currentEnemy->IsDead()) {
            std::cout << "Musuh tumbang...\n";

            enemyPool.ReturnObject(currentEnemy);
            currentEnemy = nullptr;

            static GameWinState win;
            GameManager::GetInstance().stateMachine.ChangeState(&win);
            return;
        }

        /* ===== TURN MUSUH ===== */
        currentEnemy->Update();
        currentEnemy->TryAttack(player);
        if (isStateChanging) return;
    }

    void Exit() override {
        isStateChanging = false;
        std::cout << "Keluar State Play\n";
    }

    void OnNotify(const std::string& event) override {
        if (event == "PlayerMati") {
            isStateChanging = true;
            static GameOverState gameOver;
            GameManager::GetInstance().stateMachine.ChangeState(&gameOver);
        }
    }
};
