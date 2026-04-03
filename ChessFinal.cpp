#include <iostream>
#include <string>
#include <vector>
#include "header.h"
#include <thread>

int main()
{
	gameArt();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	system("CLS");
	string board[8][8];
	Chess chess;
	int row;
	int col;
	bool restart = true;
	cout << "at any point in the game press N to start a new game or Q to exit out.\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	system("CLS");
	while (restart)
	{
		//initialize the board
		for (int r = 0; r < 8; r++) 
		{
			for (int c = 0; c < 8; c++) 
			{
				board[r][c] = "[ ]";
			}
		}
		//initializes the pawns
		for (char c = 'A'; c <= 'H'; c++)
		{
			string pos = string(1, c) + "2";
			converter(pos, row, col);
			board[row][col] = "[P]";
		}
		//initializes the rooks
		string rookPositions[] = { "A1", "H1" };
		for (const auto& pos : rookPositions)
		{
			converter(pos, row, col);
			board[row][col] = "[R]";
		}
		string bishopPositions[] = { "C1", "F1" };
		for (const auto& pos : bishopPositions)
		{
			converter(pos, row, col);
			board[row][col] = "[B]";
		}
		string knightPositions[] = { "B1", "G1" };
		for (const auto& pos : knightPositions)
		{
			converter(pos, row, col);
			board[row][col] = "[N]";
		}
		string queenPosition = "D1";
		converter(queenPosition, row, col);
		board[row][col] = "[Q]";

		string kingPosition = "E1";
		converter(kingPosition, row, col);
		board[row][col] = "[K]";
		bool active = true;
		while(active)
		{
			printBoard(board);

			string positionInput;
			cout << "Enter the position of the piece you wnat to move(Letter Number): \n";
			cin >> positionInput;
			if (positionInput == "Q" || positionInput == "q")
			{
				active = false;
				return 0;
			}
			else if (positionInput == "N" || positionInput == "n")
			{
				system("CLS");
				restart = true;
				break;
			}
			converter(positionInput, row, col);
			string piece = board[row][col];
			if (piece == "[P]" || piece == "[R]" || piece == "[B]" || piece == "[N]" || piece == "[Q]" || piece == "[K]" )
			{
				vector<pair<int, int >> moves;
				if (piece == "[P]")
				{
					chess.legalMovesPawn(board, row, col, moves);
				}
				else if (piece == "[R]")
				{
					chess.legalMovesRook(board, row, col, moves);
				}
				else if (piece == "[B]")
				{
					chess.legalMovesBishop(board, row, col, moves);
				}
				else if (piece == "[N]")
				{
					chess.legalMovesKnight(board, row, col, moves);
				}
				else if (piece == "[Q]")
				{
					chess.legalMovesQueen(board, row, col, moves);
				}
				else if (piece == "[K]")
				{
					chess.legalMovesKing(board, row, col, moves);
				}

				movesF(board, moves);
				system("CLS");
				printBoard(board);

				string moveTo;
				cout << "Enter the position to move the selected piece\n";
				cin >> moveTo;
				system("CLS");

				int moveRow;
				int moveCol;
				converter(moveTo, moveRow, moveCol);
				
				bool legalMove = false;
				for (const auto& move : moves)
				{
					if (move.first == moveRow && move.second == moveCol)
					{
						legalMove = true;
						break;
					}
				}
				if (legalMove)
				{
					moveL(board, row, col, moveRow, moveCol, piece);
					clearMoves(board);
				}
				else 
				{
					cout << "Invalid Move.\n";
					system("CLS");
					clearMoves(board);
				}
			}
			else
			{
				cout << "Invalid Input.\n";
			}
		}
	}
	return 0;
}

