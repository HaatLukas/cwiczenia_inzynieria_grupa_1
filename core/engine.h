#ifndef WARCABY_ENGINE_H
#define WARCABY_ENGINE_H

#include "timer.h"
#include "../entities/player.h"
#include "../entities/board.h"
#include "SFML/Graphics.hpp"

namespace game {

    class Engine {
        Board board;
        Player *players[2];
        Player *activePlayer;
        Player *winner;
        bool isActive;

        void checkPlayerTimers();

        void timeEnded(const Player *lost);

        void swapPlayer();

        void startGame();

        bool validateMove(coordinates c, coordinates newC);

        bool makeMove(coordinates c, coordinates newC);

        void endGame();

        void inputHandler(const sf::Event &event);

    public:
        explicit Engine(int gameTime = 120);

        void run();

        [[nodiscard]] Board getBoard() const {
            return board;
        }
    };

} // game

#endif //WARCABY_ENGINE_H
