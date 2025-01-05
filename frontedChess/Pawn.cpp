#include "Pawn.h"
#include <iostream>

Pawn::Pawn(char symbol, int color)
{
    if (symbol != 'P' && symbol != 'p')
    {
        std::cout << "Error: Invalid symbol for Pawn!" << std::endl;
    }
    else if (symbol == 'P') // white bishop
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

int Pawn::move(const std::string& source, const std::string& destination, Board& board)
{
    if (destination[0] == source[0])
        return move_Forward(source, destination, board);
    else
        return move_Diagonal(source, destination, board);
}

int Pawn::move_Forward(const std::string& source, const std::string& destination, Board& board)
{
    int irow = board.rowIndex(source[1]);
    int icol = board.colIndex(source[0]);

    int secondRow;
    int steps;
    int maxsteps;
    int rowDirection = this->color * -1;

    int i;

    if(this->color == WHITE)
        secondRow = board.rowIndex('2');
    else
        secondRow = board.rowIndex('7');


    if (irow == secondRow)
        maxsteps = 2;
    else 
        maxsteps = 1;

    steps = (destination[1] - source[1]) * rowDirection;
    if (steps > maxsteps)
        return 6; // Cannot move more than maxsteps

    if (steps < 1)
    {
        return 6; // Cannot move backward
    }

    // previous step
    for (i=1; i <= steps; i++)
        if (board.specificSquare(source[0], source[1] + i * rowDirection) != nullptr)
            return 6; // Destination cell or cell between source and destination is occupied


    return Piece::move(source, destination, board);
}

int Pawn::move_Diagonal(const std::string& source, const std::string& destination, Board& board)
{
    int irow = board.rowIndex(source[1]);
    int icol = board.colIndex(source[0]);
    int drow = board.rowIndex(destination[1]);
    int dcol = board.colIndex(destination[0]);

    int rowDirection = this->color;

    if ((drow - irow) != rowDirection)
    {
        return 6;
    }

    if (!((dcol == icol + 1) || (dcol == icol - 1)))
    {
        return 6;
    }

    Piece* targetPiece = board.specificSquare(destination[0], destination[1]);
    if (targetPiece == nullptr)
    {
        return 6;
    }

    return Piece::move(source, destination, board);
}

