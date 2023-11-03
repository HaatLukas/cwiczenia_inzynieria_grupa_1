#pragma once
#include "Board.h"


bool IsValidMove(int startX, int startY, int endX, int endY)
{
    if (Board[endX][endY] != 0)
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

void MovePiece(int startX, int startY, int endX, int endY)
{
    // Tutaj zaktualizuj plansze i przeneis warcaba.
    Board[endX][endY] = Board[startX][startY];
    Board[startX][startY] = 0;
}

void InputHan(int x, int y)
{

    if (x >= 0 && x <= 800 && y >= 0 && y <= 800)
    {
        float tempI = (float)(y - 80) / 80;
        float tempJ = (float)(x - 80) / 80;
        int i = static_cast<int>(std::ceil(tempI));
        int j = static_cast<int>(std::ceil(tempJ));
        if (selectedPieceX == -1 && selectedPieceY == -1)
        {
            if (Board[i][j] == PlayerTurn)
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
