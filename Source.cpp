#include <iostream>
#include <string>
#include <vector>
#include "header.h"

using namespace std;

void Chess::legalMovesPawn(string arr[][COLS], int row, int col,vector< pair<int, int>>& moves)
{
	//standard move up
	if (row > 0 && arr[row - 1][col] == "[ ]")
	{
		moves.push_back({ row - 1,col });
	}
	//If its on the starting row gives option to move up twice
	if (row == 6 && arr[row - 1][col] == "[ ]" && arr[row - 2][col] == "[ ]")
	{
		moves.push_back({ row - 2,col });
	}
}
void Chess::legalMovesRook(string arr[][COLS], int row, int col, vector< pair<int, int>>& moves)
{
    for (int r = row - 1; r >= 0; r--) 
    {
        if (arr[r][col] == "[ ]") 
        {
            moves.push_back({ r, col });
        }
        else 
        {
            break;
        }
    }
    // Move down
    for (int r = row + 1; r < ROWS; r++) 
    {
        if (arr[r][col] == "[ ]") 
        {
            moves.push_back({ r, col });
        }
        else 
        {
            break;
        }
    }
    // Move left
    for (int c = col - 1; c >= 0; c--) {
        if (arr[row][c] == "[ ]") 
        {
            moves.push_back({ row, c });
        }
        else 
        {
            break;
        }
    }
    // Move right
    for (int c = col + 1; c < COLS; c++) 
    {
        if (arr[row][c] == "[ ]") 
        {
            moves.push_back({ row, c });
        }
        else 
        {
            break;
        }
    }
}
void Chess::legalMovesBishop(string arr[][COLS], int row, int col, vector< pair<int, int>>& moves)
{
    //forward left
    for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--)
    {
        if (arr[r][c] == "[ ]") 
        {
            moves.push_back({ r,c });
        }
        else
        {
            break;
        }
    }
    //forward right
    for (int r = row - 1, c = col + 1; r >= 0 && c >= 0; r--, c++)
    {
        if (arr[r][c] == "[ ]")
        {
            moves.push_back({ r,c });
        }
        else
        {
            break;
        }
    }
    //down left
    for (int r = row + 1, c = col - 1; r >= 0 && c >= 0; r++, c--)
    {
        if (arr[r][c] == "[ ]")
        {
            moves.push_back({ r,c });
        }
        else
        {
            break;
        }
    }
    //down right
    for (int r = row + 1, c = col + 1; r >= 0 && c >= 0; r++, c++)
    {
        if (arr[r][c] == "[ ]")
        {
            moves.push_back({ r,c });
        }
        else
        {
            break;
        }
    }
}
void Chess::legalMovesKnight(string arr[][COLS], int row, int col, vector< pair<int, int>>& moves)
{
    // Take into account each possible move the knight can make 
    const vector<pair< int, int>> knightMoves =
    {
        {2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}
    };
    for (const auto& move : knightMoves)
    {
        int newRow = row + move.first;
        int newCol = col + move.second;
        if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && arr[newRow][newCol] == "[ ]")
        {
            moves.push_back({ newRow, newCol });
        }
    }
}
//reuses bishop and rook 
void Chess::legalMovesQueen(string arr[][COLS], int row, int col, vector< pair<int, int>>& moves)
{
    legalMovesRook(arr, row, col, moves);
    legalMovesBishop(arr, row, col, moves);
}
// Take into account each possible move the king can make 
void Chess::legalMovesKing(string arr[][COLS], int row, int col, vector<pair<int, int>>& moves)
{
    const vector<pair< int, int>> kingMoves =
    {
        {1, 0},{1,1},{0, 1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}
    };
    for (const auto& move : kingMoves)
    {
        int newRow = row + move.first;
        int newCol = col + move.second;
        if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && arr[newRow][newCol] == "[ ]")
        {
            moves.push_back({ newRow, newCol });
        }
    }
}
//converts it to readable numbers after input
void converter(const string& swap, int& row, int& col)
{
    col = swap[0] - 'A';
    row = 8 - (swap[1] - '0');
}
//prints board
void printBoard(string board[][8])
{
    cout << "   A  B  C  D  E  F  G  H\n";
    for (int r = 0; r < 8; r++)
    {
        cout << 8 - r << " ";
        for (int c = 0; c < 8; c++)
        {
            cout << board[r][c];
        }
        cout << " " << 8 - r << "\n";
     }
    cout << "   A  B  C  D  E  F  G  H\n";
}
//shows legal moves
void movesF(string board[][8], const vector<pair<int, int>>& moves)
{
    for (const auto& move : moves)
    {
        board[move.first][move.second] = "[X]";
    }
}
// clears legal moves
void clearMoves(string board[][8])
{
    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            if (board[r][c] == "[X]")
            {
                board[r][c] = "[ ]";
            }
        }
    }
}

void moveL(string board[][8], int startRow, int startCol, int endRow, int endCol, const string& piece)
{
    board[endRow][endCol] = piece;
    board[startRow][startCol] = "[ ]";
}

void gameArt()
{   
    cout << "  ___| |__   ___  ___ ___                                     \n";
    cout << " / __| '_ \\ / _ \\/ __/ __|                                  \n";
    cout << "| (__| | | |  __/\\__ \\__ \\                                 \n";
    cout << " \\___|_| |_|\\___||___/___/                                  \n";
    cout << "                                                     _:_      \n";
    cout << "                                                    '-.-'     \n";
    cout << "                                           ()      __.'.__    \n";
    cout << "                                        .-:--:-.  |_______|   \n";
    cout << "                                 ()      \\____/    \\=====/  \n";
    cout << "                                 /\\      {====}     )___(    \n";
    cout << "                      (\\=,      //\\\\      )__(     /_____\\\n";
    cout << "      __    |'-'-'|  //  .\\    (    )    /____\\     |   |   \n";
    cout << "     /  \\   |_____| (( \\_  \\    )__(      |  |      |   |  \n";
    cout << "     \\__/    |===|   ))  `\\_)  /____\\     |  |      |   |  \n";
    cout << "    /____\\   |   |  (/     \\    |  |      |  |      |   |   \n";
    cout << "     |  |    |   |   | _.-'|    |  |      |  |      |   |     \n";
    cout << "     |__|    )___(    )___(    /____\\    /____\\    /_____\\ \n";
    cout << "    (====)  (=====)  (=====)  (======)  (======)  (=======)   \n";
    cout << "    }===={  }====={  }====={  }======{  }======{  }======={   \n";
    cout << "   (______)(_______)(_______)(________)(________)(_________)  \n";

}