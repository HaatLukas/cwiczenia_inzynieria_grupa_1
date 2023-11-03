//
// Created by david on 26.10.2023.
//

#ifndef WARCABY_ENGINE_H
#define WARCABY_ENGINE_H

#include "timer.h"
#include "player.h"
#include "board.h"

namespace game {

    class Engine {
        Board board;
        Player *players[2];
        Player *activePlayer;
        Player *winner;
        bool isActive;

        void timeEnded(const Player *lost);

        void swapPlayer();

        void startGame();

        bool validateMove(coordinates c, coordinates newC);

        bool makeMove(coordinates c, coordinates newC);

        void endGame();

    public:
        explicit Engine(int gameTime = 10);

        void run();

        [[nodiscard]] Board getBoard() const {
            return board;
        }
    };

} // game

#endif //WARCABY_ENGINE_H
