
#include "board.h"
#include <iostream>


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

    void Board::movePiece(coordinates c, coordinates newC) {
        board[c.x][c.y].swap(board[newC.x][newC.y]);
    }

    void Board::movePawn(coordinates c, coordinates newC) {
        if (newC.x >= 0 && newC.x <= 800 && newC.y >= 0 && newC.y <= 800) {
            // Wykonaj ruch
            movePiece(c, newC);
        }
    }

    void Board::draw(sf::RenderTarget &target) {
        sf::Texture whiteTxt;
        sf::Texture blackTxt;
        sf::Texture BoardTxt;

        BoardTxt.loadFromFile("img/boardpn.png");
        Back = sf::Sprite(BoardTxt);
        whiteTxt.loadFromFile("img/whitepwn.png");
        whitePawn = sf::Sprite(whiteTxt);
        blackTxt.loadFromFile("img/blackpwn.png");
        blackPawn = sf::Sprite(blackTxt);
        target.draw(Back);

        blackPawn.setScale(0.92, 0.92);
        whitePawn.setScale(0.92, 0.92);
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

    void highlightSprite(sf::Sprite &sprite, bool highlight)
    {
        if (highlight)
        {
            sprite.setColor(sf::Color(255, 255, 255, 150));
            std::cout<<"HIGHLIGHTED"<<std::endl;

        } else
        {
            sprite.setColor(sf::Color::White);
            std::cout<<"UNHIGHLIGHTED"<<std::endl;
        }
    }
}

void game::Board::handleMouseInteraction(sf::RenderWindow& window)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (board[i][j] && board[i][j].value().getColor() == 1)
            {
                sf::Vector2f pawnPosition = whitePawn.getPosition();
                if (mousePosition.x >= pawnPosition.x && mousePosition.x <= pawnPosition.x + whitePawn.getGlobalBounds().width &&
                    mousePosition.y >= pawnPosition.y && mousePosition.y <= pawnPosition.y + whitePawn.getGlobalBounds().height)
                {
                    highlightSprite(whitePawn, true);
                } else
                {
                    highlightSprite(whitePawn, false);
                }
            } else if (board[i][j] && board[i][j].value().getColor() == 2)
            {
                sf::Vector2f pawnPosition = blackPawn.getPosition();
                if (mousePosition.x >= pawnPosition.x && mousePosition.x <= pawnPosition.x + blackPawn.getGlobalBounds().width &&
                    mousePosition.y >= pawnPosition.y && mousePosition.y <= pawnPosition.y + blackPawn.getGlobalBounds().height)
                {
                    highlightSprite(blackPawn, true);
                } else
                {
                    highlightSprite(blackPawn, false);
                }
            }
        }
    }
}

// core