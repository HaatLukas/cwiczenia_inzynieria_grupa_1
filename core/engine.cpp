#include "engine.h"
#include "../helpers/calculate.h"

namespace game {
    Engine::Engine(int gameTime) : players(), isActive(false), winner() {
        players[0] = new Player("1");
        players[1] = new Player("2");

        for (auto &player: players) {
            player->getTimer()->setValue(gameTime);
            player->getTimer()->init();
        }

        activePlayer = players[0];
    }

    void Engine::run() {
        sf::RenderWindow window(sf::VideoMode(1000, 800), "warcaby!",
                                sf::Style::Titlebar | sf::Style::Close);

        startGame();

        while (window.isOpen()) {
            if (isActive)
                checkPlayerTimers();

            sf::Event event{};
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                else if (event.type == sf::Event::MouseButtonPressed)
                    inputHandler(event);
            }

            window.clear();
            board.draw(window, std::to_string(players[0]->getTimer()->getValue()),
                       std::to_string(players[1]->getTimer()->getValue()));
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

    std::string timerToString(Timer& timer)
    {
        int temp = timer.getValue();
        return std::to_string(temp);
    }

    bool Engine::validateMove(coordinates c, coordinates newC) {
        if (!isActive) return false;

        std::optional<Pawn> temp = board.getPawnAt(c);

        if (board.getPawnAt(newC) && temp)
            return false;

        int dx = std::abs(newC.x - c.x);
        int dy = newC.y - c.y;

        if (activePlayer == players[0] && board.getPawnAt(c)->getColor() == 1)
            return dx == 1 && dy == -1;
        else if (activePlayer == players[1] && board.getPawnAt(c)->getColor() == 2)
            return dx == 1 && dy == 1;

        return false;
    }

    bool Engine::makeMove(coordinates c, coordinates newC) {
        if (!validateMove(c, newC)){
            board.getPawnAt(c)->setFalseVal();
            return false;
        }
        board.getPawnAt(c)->setFalseVal();
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

    void Engine::inputHandler(const sf::Event &event) {
        static coordinates startCor = {-1, -1};
        auto mouse = event.mouseButton;


        if (startCor.x == -1 || startCor.y == -1) {
            startCor = calcCoord({mouse.x, mouse.y}, 65);

            if (!board.getPawnAt(startCor))
                startCor = {-1, -1};
            else if(board.getPawnAt(startCor).value().getColor() == std::stoi(activePlayer->getName()))
                board.getPawnAt(startCor)->setTrueVal();
        } else {
            makeMove(startCor, calcCoord({mouse.x, mouse.y}, 65));
            startCor = {-1, -1};
        }
    }
} // game