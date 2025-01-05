#include <iostream>
#include "Bishop.h"

Bishop::Bishop(char symbol, int color)
{
    if (symbol != 'B' && symbol != 'b')
    {
        std::cout << "Error!" << std::endl;
    }
    else if (symbol == 'B') // white bishop
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

int Bishop::move(const std::string& source, const std::string& destination, Board& board)
{
    // source and destination positions
    char sourceX = source[0];
    char sourceY = source[1];
    char destX = destination[0];
    char destY = destination[1];

    // calculate differences
    int xDiff = destX - sourceX;
    int yDiff = destY - sourceY;

    // Check if the move is diagonal
    if ((xDiff == yDiff || xDiff == -yDiff) && (yDiff == xDiff || yDiff == -xDiff))
    {
        int path = previous_steps(source, destination, board);
        if (path == 6)
        {
            return 6; // Invalid path
        }

        return Piece::move(source, destination, board);
    }

    return 6; // not diagonal
}

int Bishop::previous_steps(const std::string& source, const std::string& destination, Board& board)
{
    int sourceCol = source[0] - 'a';
    int sourceRow = 8 - (source[1] - '0');
    int destCol = destination[0] - 'a';
    int destRow = 8 - (destination[1] - '0');

    // the direction of movement
    int colStep;
    if (destCol > sourceCol)
    {
        colStep = 1; // right
    }
    else
    {
        colStep = -1; // left
    }

    int rowStep;
    if (destRow > sourceRow) 
    {
        rowStep = 1; // up
    }
    else
    {
        rowStep = -1; // down
    }

    // check each square along the path
    int currentRow = sourceRow + rowStep;
    int currentCol = sourceCol + colStep;

    while (currentRow != destRow && currentCol != destCol)
    {
        if (board.board[currentRow][currentCol] != nullptr)
        {
            return 6; // path blocked
        }

        // next square
        currentRow += rowStep;
        currentCol += colStep;
    }

    return 0;
}
