#include <iostream>
#include "Rook.h"

Rook::Rook(char symbol, int color)
{
    if (symbol != 'R' && symbol != 'r')
    {
        std::cout << "Error!" << std::endl;
    }
    else if (symbol == 'R') // white bishop
    {
        this->sighted = symbol;
        this->turn = 0; // white turn
        this->color = 1;
    }
    else
    {
        this->sighted = symbol;
        this->turn = 1; // black turn
        this->color = -1;
    }
}

int Rook::move(const std::string& source, const std::string& destination, Board& board)
{
    if (source[0] != destination[0] && source[1] != destination[1])
    {
        return 6;
    }

    int path = previous_steps(source, destination, board);
    if (path == 6)
    {
        return 6; // invalid path
    }

    return Piece::move(source, destination, board);
}

int Rook::previous_steps(const std::string& source, const std::string& destination, Board& board)
{
    int sourceCol = source[0] - 'a';
    int sourceRow = 8 - (source[1] - '0');
    int destCol = destination[0] - 'a';
    int destRow = 8 - (destination[1] - '0');

    if (sourceCol == destCol) // Vertical movement
    {
        int step;
        if (destCol > sourceCol) 
        {
            step = 1; // Moving right
        }
        else
        {
            step = -1; // Moving left
        }
        for (int row = sourceRow + step; row != destRow; row += step)
        {
            if (board.board[row][sourceCol] != nullptr)
            {
                return 6; // Path is blocked
            }
        }
    }
    else if (sourceRow == destRow) // Horizontal movement
    {
        int step;
        if (destCol > sourceCol)
        {
            step = 1; // Moving right
        }
        else
        {
            step = -1; // Moving left
        }

        for (int col = sourceCol + step; col != destCol; col += step)
        {
            if (board.board[sourceRow][col] != nullptr)
            {
                return 6; // Path is blocked
            }
        }
    }
    else
    {
        return 6; // Invalid movement
    }

    return 0; // Path is clear
}
