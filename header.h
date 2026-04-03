
#ifndef header

#define header
#include <iostream>
#include <string>
#include <vector>

using namespace std;

 const int ROWS = 8;
 const int COLS = 8;
class Chess 
{
public:
	void legalMovesPawn(string arr[][COLS], int row, int col, vector<pair<int, int>>& moves);
	void legalMovesRook(string arr[][COLS], int row, int col, vector<pair<int, int>>& moves);
	void legalMovesBishop(string arr[][COLS], int row, int col, vector<pair<int, int>>& moves);
	void legalMovesKnight(string arr[][COLS], int row, int col, vector<pair<int, int>>& moves);
	void legalMovesQueen(string arr[][COLS], int row, int col, vector<pair<int, int>>& moves);
	void legalMovesKing(string arr[][COLS], int row, int col, vector<pair<int, int>>& moves);



};

void converter(const string& swap, int& row, int& col);
void printBoard(string board[][8]);
void movesF(string board[][8], const vector<pair<int, int>>& moves);
void clearMoves(string board[][8]);
void moveL(string board[][8], int startRow, int startCol, int endRow, int endCol, const string& piece);
void gameArt();
#endif
