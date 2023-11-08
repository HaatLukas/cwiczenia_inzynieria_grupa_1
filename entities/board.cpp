
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

    void Board::draw(sf::RenderTarget &target, std::string val1, std::string val2) {
        sf::Sprite back = loadSprite("img/board.png");
        sf::Sprite whitePawn = loadSprite("img/blackpwn.png");
        sf::Sprite blackPawn = loadSprite("img/whitepwn.png");
        sf::Sprite selectedB = loadSprite("img/selected.png");

        sf::Font font;
        font.loadFromFile("fonts/KoHo-Regular.ttf");
        sf::Text timer1;
        timer1.setFont(font);
        sf::Text timer2;
        timer1.setFont(font);
        timer2.setFont(font);
        timer1.setCharacterSize(24);
        timer2.setCharacterSize(24);

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
                if(board[i][j].has_value() && board[i][j].value().selectedValue()) {
                    selectedB.setPosition(sf::Vector2f(65 + 1.2 * i + (65 * i), 65 + j * 2 + (65 * j)));
                    target.draw(selectedB);
                }
            }
        }
        //drawing timers
        timer1.setPosition(sf::Vector2f(768, 482));
        timer2.setPosition(sf::Vector2f(768, 117));
        timer1.setString(val1);
        timer2.setString(val2);
        target.draw(timer1);
        target.draw(timer2);
    }
} // game