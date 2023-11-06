
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



    public:
        Board();

        board_t board;

        void movePiece(coordinates c, coordinates newC);

        void movePawn(coordinates c, coordinates newC);

        void draw(sf::RenderTarget &target);

        void handleMouseInteraction(sf::RenderWindow& window);

        [[nodiscard]] std::optional<Pawn> getPawnAt(coordinates c) const {
            return board[c.x][c.y];
        }

        sf::Sprite Back;
        sf::Sprite whitePawn;
        sf::Sprite blackPawn;
    };

} // core

#endif //WARCABY_BOARD_H
