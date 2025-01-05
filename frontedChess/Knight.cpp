#include <iostream>
#include "Knight.h"

Knight::Knight(char symbol, int color)
{
    if (symbol != 'N' && symbol != 'n')
    {
        std::cout << "Error!" << std::endl;
    }
    else if (symbol == 'N') // white bishop
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

int Knight::move(const std::string& source, const std::string& destination, Board& board)
{
    // Calculate differences in file and rank
    int fileDiff = source[0] - destination[0];
    int rankDiff = source[1] - destination[1];

    // Check if the move follows an "L" shape
    if (!((fileDiff == 2 && rankDiff == 1) || (fileDiff == 2 && rankDiff == -1) || (fileDiff == -2 && rankDiff == 1) || (fileDiff == -2 && rankDiff == -1) || (fileDiff == 1 && rankDiff == 2) || (fileDiff == 1 && rankDiff == -2) || (fileDiff == -1 && rankDiff == 2) || (fileDiff == -1 && rankDiff == -2)))
    {
        return 6;
    }

    return Piece::move(source, destination, board);
}
