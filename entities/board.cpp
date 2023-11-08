
#include "board.h"
#include "../helpers/load_res.h"


namespace game {
    Board::Board(Player *player1, Player *player2) {
        for (int i = 0; i < 10; i += 2)
            for (int j = 0; j < 4; j++) {
                board[(j % 2 == 0 ? 1 : 0) + i][6 + j] = Pawn(player1, 1);
                board[(j % 2 == 0 ? 1 : 0) + i][0 + j] = Pawn(player2, 2);
            }
    }

    void Board::movePiece(coordinates c, coordinates newC) {
        board[c.x][c.y].swap(board[newC.x][newC.y]);
    }

    void Board::movePawn(coordinates c, coordinates newC) {
        movePiece(c, newC);
    }

    void Board::draw(sf::RenderTarget &target, const std::string &timerVal1, const std::string &timerVal2) {
        sf::Sprite back = loadSprite("img/board.png");
        sf::Sprite whitePawn = loadSprite("img/whitepwn.png");
        sf::Sprite blackPawn = loadSprite("img/blackpwn.png");
        sf::Sprite selectedB = loadSprite("img/selected.png");

        selectedB.setScale(1, 1.025);

        sf::Font font;
        font.loadFromFile("fonts/KoHo-Bold.ttf");

        sf::Text timer1;
        sf::Text timer2;

        timer1.setFont(font);
        timer2.setFont(font);
        timer1.setCharacterSize(64);
        timer2.setCharacterSize(64);

        target.draw(back);

        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++) {
                if (board[i][j] && board[i][j]->getColor() == 1) {
                    blackPawn.setPosition(sf::Vector2f(69 + 1.3 * i + (65 * i), 69 + j * 2.3 + (65 * j)));
                    target.draw(blackPawn);
                } else if (board[i][j] && board[i][j]->getColor() == 2) {
                    whitePawn.setPosition(sf::Vector2f(69 + i * 1.3 + (65 * i), 69 + j * 2.3 + (65 * j)));
                    target.draw(whitePawn);
                }

                if (board[i][j] && board[i][j]->isSelected()) {
                    selectedB.setPosition(sf::Vector2f(65 + 1.1 * i + (65 * i), 65 + j * 2 + (65 * j)));
                    target.draw(selectedB);
                }
            }

        timer1.setPosition(sf::Vector2f(768, 452));
        timer2.setPosition(sf::Vector2f(768, 77));
        timer1.setString(timerVal1);
        timer2.setString(timerVal2);
        target.draw(timer1);
        target.draw(timer2);
    }
} // game