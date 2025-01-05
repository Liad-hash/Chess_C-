#include "Board.h"
#include "King.h"
#include <iostream>

Board::Board()
{
    // Initialize board with nullptr
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            board[i][j] = nullptr;
        }
    }
    addPieces();
}

Board::~Board() 
{
    // Free dynamically allocated memory for pieces
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            delete board[i][j];
            board[i][j] = nullptr;
        }
    }
}

void Board::addPieces()
{
    // Place white major pieces
    board[0][0] = new Rook('R', WHITE);    // Rook
    board[0][1] = new Knight('N', WHITE);  // Knight
    board[0][2] = new Bishop('B', WHITE);  // Bishop
    board[0][3] = new Queen('Q', WHITE);   // Queen
    board[0][4] = new King('K', WHITE);    // King
    board[0][5] = new Bishop('B', WHITE);  // Bishop
    board[0][6] = new Knight('N', WHITE);  // Knight
    board[0][7] = new Rook('R', WHITE);    // Rook

    // Place white pawns
    for (int j = 0; j < 8; ++j)
    {
        board[1][j] = new Pawn('P', WHITE);
    }

    // Place black major pieces
    board[7][0] = new Rook('r', BLACK);    // Rook
    board[7][1] = new Knight('n', BLACK);  // Knight
    board[7][2] = new Bishop('b', BLACK);  // Bishop
    board[7][4] = new Queen('q', BLACK);   // Queen
    board[7][3] = new King('k', BLACK);    // King
    board[7][5] = new Bishop('b', BLACK);  // Bishop
    board[7][6] = new Knight('n', BLACK);  // Knight
    board[7][7] = new Rook('r', BLACK);    // Rook

    // Place black pawns
    for (int j = 0; j < 8; ++j)
    {
        board[6][j] = new Pawn('p', BLACK);
    }
}

char* Board::boardSTR()
{
    char* boardString = new char[8 * 8 + 2];
    int index = 0;

    for (int i = 0; i < 8; ++i) 
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[i][j] != nullptr)
            {
                boardString[index++] = board[i][j]->getSighted();
            }
            else
            {
                boardString[index++] = '#';
            }
        }
    }

    boardString[index++] = '0'; // White starts by default
    boardString[index] = '\0'; // Null-terminate the string

    return boardString;
}


Piece* Board::specificSquare(char col, char row)
{
    int IndexCOL = colIndex(col);
    int rowIndex = '8' - row;
    

    // Check if the indices are within the valid range (0-7)
    if (IndexCOL < 0 || IndexCOL >= 8 || rowIndex < 0 || rowIndex >= 8)
    {
        return nullptr; // Invalid square
    }

    return board[rowIndex][IndexCOL]; // Return the piece directly (nullptr if empty)
}

int Board::colIndex(char col)
{
    int colIndex = col - 'a'; // Convert 'a'-'h' to 0-7
    return colIndex;
    
}

int Board::rowIndex(char row)
{
    int rowIndex = '8' - row; // Convert '1'-'8' to 0-7
    return rowIndex;
}

/*
int Board::isCheck(char kingSighted)
{
    int kingRow = -1, kingCol = -1;
    bool kingFound = false;

    // Locate the king on the board
    for (int i = 0; i < 8 && !kingFound; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] != nullptr && board[i][j]->getSighted() == kingSighted)
            {
                kingRow = i;
                kingCol = j;
                kingFound = true;
                break;
            }
        }
    }

    // Check if any opponent piece can move to the king's position
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Piece* piece = board[i][j];
            if (piece != nullptr && piece->getSighted() != kingSighted)
            {
                std::string from = std::string(1, 'a' + j) + std::to_string(8 - i);
                std::string to = std::string(1, 'a' + kingCol) + std::to_string(8 - kingRow);

                // Check if the piece can legally move to the king's position
                if (piece->move(from, to, *this) == 0)
                {
                    return 1; // King is in check
                }
            }
        }
    }

    return 0; // King is not in check
}

*/
