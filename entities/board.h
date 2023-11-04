
#ifndef WARCABY_BOARD_H
#define WARCABY_BOARD_H

#include <array>
#include "pawn.h"
#include "SFML/Graphics.hpp"
#include <optional>

namespace game {
    typedef std::array<std::array<std::optional<Pawn>, 10>, 10> board_t;

    struct coordinates {
        int x, y;
    };

    class Board {
        board_t board;
        sf::Texture whiteTxt;
        sf::Texture blackTxt;
        sf::Texture BoardTxt;


    public:
        Board();

        void movePiece(int startX, int startY, int endX, int endY);

        void movePawn(coordinates c, coordinates newC);

        void draw(sf::RenderTarget &target);

        [[nodiscard]] std::optional<Pawn> getPawnAt(coordinates c) const {
            return board[c.x][c.y];
        }
    };

} // core

#endif //WARCABY_BOARD_H
