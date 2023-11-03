
#include "board.h"


namespace game {
    Board::Board() {

    }

    void Board::Initialize()
    {
            // 2 czarny // 1 bialy
            for (int i = 0; i < 10; i += 2)
            {
                board[0][i + 1].setColor(2);
                board[1][i].setColor(2);
                board[2][i + 1].setColor(2);
                board[3][i].setColor(2);

                board[6][i + 1].setColor(1);
                board[7][i].setColor(1);
                board[8][i + 1].setColor(1);
                board[9][i].setColor(1);
            }
    }

    bool Board::IsValidMove(int startX, int startY, int endX, int endY)
    {
        if (board[endX][endY].getColor() != 0)
            return false;

        // Sprawdz, czy ruch jest o jedno pole do przodu wzdluz przekatnych.
        int dx = std::abs(endX - startX);
        int dy = std::abs(endY - startY);

        if ((dx == 1 && dy == 1) &&
            ((PlayerTurn == 1 && endX > startX) || (PlayerTurn == 2 && endX < startX)))
        {
            // Ruch o jedno pole do przodu po przekatnej jest dozwolony.
            return true;
        }
    }

    void Board::MovePiece(int startX, int startY, int endX, int endY)
    {
        board[endX][endY] = board[startX][startY];
        board[startX][startY].setColor(0);
    }

    void Board::movePawn(int x, int y) {
        if (x >= 0 && x <= 800 && y >= 0 && y <= 800)
        {
            float tempI = (float)(y - 80) / 80;
            float tempJ = (float)(x - 80) / 80;
            int i = static_cast<int>(std::ceil(tempI));
            int j = static_cast<int>(std::ceil(tempJ));
            if (selectedPieceX == -1 && selectedPieceY == -1)
            {
                if (board[i][j].getColor() == PlayerTurn)
                {
                    selectedPieceX = i;
                    selectedPieceY = j;
                }
            }
                // Jesli wybrano juz warcaba, to sprobuj wykonac ruch lub bicie.
            else
            {
                // Sprawdz, czy ruch jest dozwolony i aktualizuj plansze.
                if (IsValidMove(selectedPieceX, selectedPieceY, i, j))
                {
                    // Wykonaj ruch
                    MovePiece(selectedPieceX, selectedPieceY, i, j);
                    // Przelacz ture gracza.
                    if (PlayerTurn == 1)
                        PlayerTurn = 2;
                    else
                        PlayerTurn = 1;
                }
                // Zresetuj wybor warcaba.
                selectedPieceX = -1;
                selectedPieceY = -1;
            }
        }
    }

    void Board::Draw(sf::RenderTarget& target)
    {
        BoardTxt.loadFromFile("img/boardpn.png");
        sf::Sprite Back(BoardTxt);
        whiteTxt.loadFromFile("img/whitepwn.png");
        sf::Sprite whitePawn(whiteTxt);
        blackTxt.loadFromFile("img/blackpwn.png");
        sf::Sprite blackPawn(blackTxt);
        target.draw(Back);

        blackPawn.setScale(0.92, 0.92);
        whitePawn.setScale(0.92, 0.92);
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (board[i][j].getColor() == 1)
                {
                    whitePawn.setPosition(sf::Vector2f(80 * j, 80 * i));
                    target.draw(whitePawn);
                }
                else if (board[i][j].getColor() == 2)
                {
                    blackPawn.setPosition(sf::Vector2f(80 * j, 80 * i));
                    target.draw(blackPawn);
                }
            }
        }
    }
} // core