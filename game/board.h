//
// Created by david on 03.11.2023.
//

#ifndef WARCABY_BOARD_H
#define WARCABY_BOARD_H

#include <array>
#include "pawn.h"

namespace game {
    typedef std::array<std::array<Pawn, 10>, 10> board_t;

    struct coordinates {
        int x, y;
    };

    class Board {
        board_t board;

    public:
        Board();

        void movePawn(coordinates c, coordinates newC);

        [[nodiscard]] Pawn getPawnAt(coordinates c) const {
            return board[c.x][c.y];
        }
    };

} // game

#endif //WARCABY_BOARD_H
