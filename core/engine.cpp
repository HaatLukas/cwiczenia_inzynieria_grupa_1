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
                timeEnded(player);
            });

        activePlayer = players[0];
    }

    // TODO
    void Engine::run() {
        startGame(); // TODO: po naciśnięciu "rozpocznij grę" ta funkcja powinna zostać wywołana
        sf::RenderWindow window(sf::VideoMode(800, 800), "warcaby!");
        board.Initialize();
        while (true)
        {

            while (window.isOpen())
            {

                sf::Event event;

                while (window.pollEvent(event))
                {

                    if (event.type == sf::Event::Closed)
                        window.close();

                    else if (event.type == sf::Event::MouseButtonPressed)
                    {
                        board.movePawn(event.mouseButton.x, event.mouseButton.y);
                        //score = Update();
                        //std::cout << score << std::endl;

                    }

                }
                window.clear();

                board.Draw(window);
                window.display();

            }
        }
    }

    void Engine::timeEnded(const Player *lost) {
        for (auto &player: players)
            if (player != lost)
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

/*    bool Engine::makeMove(coordinates c, coordinates newC) {
        if (!validateMove(c, newC)) return false;

        board.movePawn(c, newC);
        swapPlayer();

        return true;
    }*/

    // TODO
    void Engine::endGame() {
        isActive = false;

        for (auto &player: players)
            player->getTimer()->stop();

        std::cout << "Gracz " << winner->getName() << " wygral!";
    }
} // core