#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

class Board 
{
public:
    Piece* board[8][8]; // 8x8 chessboard represented by pointers to Piece objects

    Board(); 
    ~Board(); 

    void addPieces();   // Place all pieces on the board
    char* boardSTR(); // Get a string representation of the board
    Piece* specificSquare(char col, char row); // Get the piece at a specific square
    void printBoard();  // Print the board

    int colIndex(char col);
    int rowIndex(char row);

    // int isCheck(char kingSighted);
};

#endif
