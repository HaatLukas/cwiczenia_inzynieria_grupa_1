#include <cmath>
#include "engine.h"

namespace game {
    Engine::Engine(int gameTime) : winner(nullptr), players(), activePlayer(nullptr), isActive(false) {
        players[0] = new Player("1");
        players[1] = new Player("2");

        for (auto &player: players) {
            player->getTimer()->setValue(gameTime);
            player->getTimer()->init();
        }

        activePlayer = players[0];
    }

    // TODO
    void Engine::run() {
        coordinates startCor = {-1, -1};

        sf::RenderWindow window(sf::VideoMode(800, 800), "warcaby!", sf::Style::Titlebar | sf::Style::Close);
        startGame();

        while (window.isOpen()) {
            if (isActive)
                checkPlayerTimers();

            sf::Event event;

            while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed)
                    window.close();

                else if (event.type == sf::Event::MouseButtonPressed) {
                    auto mouse = event.mouseButton;

                    if (startCor.x == -1 || startCor.y == -1) {
                        startCor = {static_cast<int>(std::ceil((float) (mouse.x - 80) / 80)),
                                    static_cast<int>(std::ceil((float) (mouse.y - 80) / 80))};
                    } else {
                        makeMove(startCor, {static_cast<int>(std::ceil((float) (mouse.x - 80) / 80)),
                                                         static_cast<int>(std::ceil((float) (mouse.y - 80) / 80))});
                        startCor = {-1, -1};
                    }
                    //score = Update();
                    //std::cout << score << std::endl;
                }

            }
            window.clear();

            board.draw(window);
            window.display();

        }
    }

    void Engine::checkPlayerTimers() {
        for (auto &player: players)
            if (player->getTimer()->getValue() <= 0)
                timeEnded(player);
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
            if (player != activePlayer) {
                activePlayer = player;
                break;
            }

        activePlayer->getTimer()->resume();
    }

    // TODO
    bool Engine::validateMove(coordinates c, coordinates newC) {
        if (!isActive) return false;

        if (board.getPawnAt(newC))
            return false;

        // Sprawdz, czy ruch jest o jedno pole do przodu wzdluz przekatnych.
        int dx = std::abs(newC.x - c.x);
        int dy = (newC.y - c.y);
        std::optional<Pawn> temp = board.getPawnAt(c);
        if(temp) {
            if (activePlayer == players[0] && board.getPawnAt(c)->getColor() == 1) {
                if (dx == 1 && dy == -1)
                    return true;
                else
                    return false;
            } else if (activePlayer == players[1] && board.getPawnAt(c)->getColor() == 2) {
                if (dx == 1 && dy == 1)
                    return true;
                else
                    return false;
            }
        }
        return false;
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
    }
} // core