#include <iostream>
#include "Queen.h"

Queen::Queen(char symbol, int color)
{
    if (symbol != 'Q' && symbol != 'q')
    {
        std::cout << "Error!" << std::endl;
    }
    else if (symbol == 'Q') // white bishop
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

int Queen::move(const std::string& source, const std::string& destination, Board& board)
{
    // check if the move is valid as a rook
    if (moveLikeRook(source, destination, board) == 0)
    {
        return 0; // valid rook like move
    }

    // Check if the move is valid as a bishop
    if (moveLikeBishop(source, destination, board) == 0)
    {
        return 0; // valid bishop like move
    }

    return 6; // invalid move
}

int Queen::moveLikeRook(const std::string& source, const std::string& destination, Board& board)
{
    if (source[0] != destination[0] && source[1] != destination[1])
    {
        return 6;
    }

    int path = previous_steps_rook(source, destination, board);
    if (path == 6)
    {
        return 6; // invalid path
    }

    return Piece::move(source, destination, board);
}

int Queen::previous_steps_rook(const std::string& source, const std::string& destination, Board& board)
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


int Queen::moveLikeBishop(const std::string& source, const std::string& destination, Board& board)
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
        int path = previous_steps_bishop(source, destination, board);
        if (path == 6)
        {
            return 6; // Invalid path
        }

        return Piece::move(source, destination, board);
    }

    return 6; // not diagonal
}

int Queen::previous_steps_bishop(const std::string& source, const std::string& destination, Board& board)
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
