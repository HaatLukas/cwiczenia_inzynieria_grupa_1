
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

    void Board::draw(sf::RenderTarget &target, const std::string& val1, const std::string& val2) {
        sf::Sprite back = loadSprite("img/board.png");
        sf::Sprite whitePawn = loadSprite("img/blackpwn.png");
        sf::Sprite blackPawn = loadSprite("img/whitepwn.png");
        sf::Sprite selectedB = loadSprite("img/selected.png");

        sf::Font font;
        font.loadFromFile("fonts/KoHo-Bold.ttf");

        sf::Text timer1;
        sf::Text timer2;

        timer1.setFont(font);
        timer2.setFont(font);
        timer1.setCharacterSize(64);
        timer2.setCharacterSize(64);

        target.draw(back);
        blackPawn.setScale(0.4514, 0.4514);
        whitePawn.setScale(0.68, 0.68);
        selectedB.setScale(0.95, 0.95);

        // TODO: refactor

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (board[i][j] && board[i][j].value().getColor() == 1) {
                    whitePawn.setPosition(sf::Vector2f(65 + 1.2 * i + (65 * i), 65 + j * 2.2 + (65 * j)));
                    target.draw(whitePawn);
                } else if (board[i][j] && board[i][j].value().getColor() == 2) {
                    blackPawn.setPosition(sf::Vector2f(65 + i * 1.2 +(65 * i), 65 + j * 2.2 +(65 * j)));
                    target.draw(blackPawn);
                }
                if(board[i][j] && board[i][j]->isSelected()) {
                    selectedB.setPosition(sf::Vector2f(65 + 1.2 * i + (65 * i), 65 + j * 2 + (65 * j)));
                    target.draw(selectedB);
                }
            }
        }
        //drawing timers
        timer1.setPosition(sf::Vector2f(768, 452));
        timer2.setPosition(sf::Vector2f(768, 77));
        timer1.setString(val1);
        timer2.setString(val2);
        target.draw(timer1);
        target.draw(timer2);
    }
} // game