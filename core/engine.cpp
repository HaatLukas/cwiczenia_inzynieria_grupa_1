//
// Created by david on 26.10.2023.
//

#include <iostream>
#include "engine.h"

namespace game {
    Engine::Engine(int gameTime) : winner(nullptr), players(), activePlayer(nullptr), isActive(false) {
        players[0] = new Player("1");
        players[1] = new Player("2");

        for (auto &player: players)
            player->getTimer()->setValue(gameTime);

        for (auto &player: players)
            player->getTimer()->run([&](int val) {
                std::cout << val << " gracz " << player->getName() << "\n"; // TODO: val to aktualna wartość timer'a
            }, [&]() {
                timeEnded();
            });

        activePlayer = players[0];
    }

    // TODO
    void Engine::run() {
        startGame(); // TODO: po naciśnięciu "rozpocznij grę" ta funkcja powinna zostać wywołana

        while (true) {}
    }

    void Engine::timeEnded() {
        for (auto &player: players)
            if (player->getTimer()->getValue() <= 0)
                winner = player;

        endGame();
    }

    void Engine::startGame() {
        isActive = true;
        activePlayer->getTimer()->resume();
    }

    void Engine::swapPlayer() {
        activePlayer->getTimer()->stop();

        for (auto &player: players)
            if (player != activePlayer)
                activePlayer = player;

        activePlayer->getTimer()->resume();
    }

    // TODO
    bool Engine::validateMove(coordinates c, coordinates newC) {
        if (!isActive) return false;

        return true;
    }

    bool Engine::makeMove(coordinates c, coordinates newC) {
        if (!validateMove(c, newC)) return false;

        board.movePawn(c, newC);
        swapPlayer();

        return true;
    }

    // TODO
    void Engine::endGame() {
        isActive = false;

        for (auto &player: players)
            player->getTimer()->stop();

        std::cout << "Gracz " << winner->getName() << " wygral!";
    }
} // core