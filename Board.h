#pragma once

int Board[10][10] = { 0 };
int PlayerTurn = 1;
int score = 0;




sf::Texture whiteTxt;
sf::Texture blackTxt;
sf::Texture BoardTxt;
int selectedPieceX = -1;
int selectedPieceY = -1;
int targetX = -1;
int targetY = -1;

void Initialize()
{
    // 2 czarny // 1 bialy
    for (int i = 0; i < 10; i += 2)
    {
        Board[0][i + 1] = 2;
        Board[1][i] = 2;
        Board[2][i + 1] = 2;
        Board[3][i] = 2;

        Board[6][i + 1] = 1;
        Board[7][i] = 1;
        Board[8][i + 1] = 1;
        Board[9][i] = 1;
    }
}

void Draw(sf::RenderTarget& target)
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
            if (Board[i][j] == 1)
            {
                whitePawn.setPosition(sf::Vector2f(80 * j, 80 * i));
                target.draw(whitePawn);
            }
            else if (Board[i][j] == 2)
            {
                blackPawn.setPosition(sf::Vector2f(80 * j, 80 * i));
                target.draw(blackPawn);
            }
        }
    }
}