
#ifndef WARCABY_BOARD_H
#define WARCABY_BOARD_H

#include <array>
#include "pawn.h"
#include "SFML/Graphics.hpp"
#include <cmath>

namespace game {
    typedef std::array<std::array<Pawn, 10>, 10> board_t;

    struct coordinates {
        int x, y;
    };

    class Board {
        int PlayerTurn;
        board_t board;
        sf::Texture whiteTxt;
        sf::Texture blackTxt;
        sf::Texture BoardTxt;
        int selectedPieceX = -1;
        int selectedPieceY = -1;
        int targetX = -1;
        int targetY = -1;


    public:
        Board();
        void Initialize();
        bool IsValidMove(int startX, int startY, int endX, int endY);
        void MovePiece(int startX, int startY, int endX, int endY);
        void movePawn(int x, int y);
        void Draw(sf::RenderTarget& target);

        [[nodiscard]] Pawn getPawnAt(coordinates c) const {
            return board[c.x][c.y];
        }
    };

} // core

#endif //WARCABY_BOARD_H
