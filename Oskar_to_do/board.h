#pragma once
class Board
{

public:
	int board[10][10]; // 0 - brak bierki // 1 - bierka biala // 2 - bierka czarna
	void initBoard()
	{
		for(int i = 1; i < 10; i+=2)
		{
			board[0][i] = 2;
			board[2][i] = 2;
			board[7][i] = 1;
			board[9][i] = 1;
		}
		for(int i = 0; i < 10; i+=2)
		{
			board[1][i] = 
			board[3]
			board[8]
				[10]
		}
	}




};