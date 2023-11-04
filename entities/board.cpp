
#include "board.h"


namespace game {
    Board::Board() {
        // 2 czarny // 1 bialy
        for (int i = 0; i < 10; i += 2) {
            board[i + 1][0] = Pawn(2);
            board[i][1] = Pawn(2);
            board[i + 1][2] = Pawn(2);
            board[i][3] = Pawn(2);

            board[i + 1][6] = Pawn(1);
            board[i][7] = Pawn(1);
            board[i + 1][8] = Pawn(1);
            board[i][9] = Pawn(1);
        }
    }

    void Board::movePiece(int startX, int startY, int endX, int endY) {
        board[startX][startY].swap(board[endX][endY]);
    }

    void Board::movePawn(coordinates c, coordinates newC) {
        if (newC.x >= 0 && newC.x <= 800 && newC.y >= 0 && newC.y <= 800) {
            // Wykonaj ruch
            movePiece(c.x, c.y, newC.x, newC.y);
        }
    }

    void Board::draw(sf::RenderTarget &target) {
        BoardTxt.loadFromFile("img/boardpn.png");
        sf::Sprite Back(BoardTxt);
        whiteTxt.loadFromFile("img/whitepwn.png");
        sf::Sprite whitePawn(whiteTxt);
        blackTxt.loadFromFile("img/blackpwn.png");
        sf::Sprite blackPawn(blackTxt);
        target.draw(Back);

        blackPawn.setScale(0.92, 0.92);
        whitePawn.setScale(0.92, 0.92);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (board[i][j] && board[i][j].value().getColor() == 1) {
                    whitePawn.setPosition(sf::Vector2f(80 * i, 80 * j));
                    target.draw(whitePawn);
                } else if (board[i][j] && board[i][j].value().getColor() == 2) {
                    blackPawn.setPosition(sf::Vector2f(80 * i, 80 * j));
                    target.draw(blackPawn);
                }
            }
        }
    }
} // core