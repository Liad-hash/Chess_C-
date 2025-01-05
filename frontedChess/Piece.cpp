#include <iostream>
#include "Piece.h"
#include "Game.h"
#include "Board.h"
#include "King.h"

Piece::~Piece() 
{
}

int Piece::activeSquareTests(const std::string& activePosition)
{
    if (activePosition.length() == 2)
    {
        char col = activePosition[0];
        char row = activePosition[1];
        if (col < 'a' || col > 'h' || row < '1' || row > '8')
        {
            return 5; // Invalid position
        }
        return true;
    }
    return 5;
}

int Piece::squareMoveTests(const std::string& squareMove)
{
    return activeSquareTests(squareMove);
}


char Piece::getSighted() const
{
    return this->sighted;
}

int Piece::move(const std::string& activePosition, const std::string& squareMove, Board& board)
{
    if (activeSquareTests(activePosition) != true || squareMoveTests(squareMove) != true)
    {
        return 5; // Invalid position
    }

    int activeCol = activePosition[0] - 'a';
    int activeRow = 8 - (activePosition[1] - '0');
    int moveCol = squareMove[0] - 'a';
    int moveRow = 8 - (squareMove[1] - '0');

    Piece* currentPiece = board.board[activeRow][activeCol];
    if (currentPiece->turn != board.specificSquare(activePosition[0], activePosition[1])->turn)
    {
        return 6; // Not the player's turn
    }

    if (activeRow == moveRow && activeCol == moveCol)
    {
        return 7; // Source and destination are the same
    }

    Piece* targetPiece = board.specificSquare(squareMove[0], squareMove[1]);
    if (targetPiece != nullptr && targetPiece->turn == currentPiece->turn)
    {
        return 3; // Target occupied by same player's piece
    }
    
    /*
    int turnPlayer = currentPiece->turn;
    King* selfKing = nullptr;
    int check = 0;
    
    // Simulate the move on a temporary board
    Board tempBoard = board;
    tempBoard.board[moveRow][moveCol] = currentPiece;
    tempBoard.board[activeRow][activeCol] = nullptr;

    // Check if the move puts the self king in check
    if (turnPlayer == 0) // white turn (white king)
    {
        selfKing = new King('K', WHITE);
        check = tempBoard.isCheck(selfKing->getSighted());
        
    }
    else // black turn (black king)
    {
        selfKing = new King('k', BLACK);
        check = tempBoard.isCheck(selfKing->getSighted());
    }

    if(check == 1)
    {
        return 4; // move results in self-check
    }

    // move the piece
    board.board[moveRow][moveCol] = currentPiece;
    board.board[activeRow][activeCol] = nullptr;

    // Check if the move puts the opponent king in check
    if (turnPlayer == 1) // black turn (white king)
    {
        selfKing = new King('K', WHITE);
        check = tempBoard.isCheck(selfKing->getSighted());

    }
    else // white turn (black king)
    {
        selfKing = new King('k', BLACK);
        check = tempBoard.isCheck(selfKing->getSighted());
    }

    if (check == 1)
    {
        return 1; // move create a check on the opponent (Successful move)
    }
    */

    // move the piece
    board.board[moveRow][moveCol] = currentPiece;
    board.board[activeRow][activeCol] = nullptr;
    return 0; // Successful move
}
