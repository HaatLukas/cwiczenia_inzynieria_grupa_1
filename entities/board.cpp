
#include "board.h"
#include "../helpers/load_res.h"


namespace game {
    Board::Board() {
        for (int i = 0; i < 10; i += 2)
            for (int j = 0; j < 4; j++) {
                board[(j % 2 == 0 ? 1 : 0) + i][0 + j] = Pawn(2);
                board[(j % 2 == 0 ? 1 : 0) + i][6 + j] = Pawn(1);
            }
    }

    void Board::movePiece(coordinates c, coordinates newC) {
        board[c.x][c.y].swap(board[newC.x][newC.y]);
    }

    void Board::movePawn(coordinates c, coordinates newC) {
        movePiece(c, newC);
    }

    void Board::draw(sf::RenderTarget &target) {
        sf::Sprite back = loadSprite("img/boardpn.png");
        sf::Sprite whitePawn = loadSprite("img/whitepwn.png");
        sf::Sprite blackPawn = loadSprite("img/blackpwn.png");

        target.draw(back);
        blackPawn.setScale(0.92, 0.92);
        whitePawn.setScale(0.92, 0.92);

        // TODO: refactor
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (board[i][j] && board[i][j].value().getColor() == 1) {
                    whitePawn.setPosition(sf::Vector2f(81 * i, 81 * j));
                    target.draw(whitePawn);
                } else if (board[i][j] && board[i][j].value().getColor() == 2) {
                    blackPawn.setPosition(sf::Vector2f(81 * i, 81 * j));
                    target.draw(blackPawn);
                }
            }
        }
    }
} // game