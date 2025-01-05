#include <iostream>
#include "King.h"

King::King(char symbol, int color)
{
    if (symbol != 'K' && symbol != 'k')
    {
        std::cout << "Error!" << std::endl;
    }
    else if (symbol == 'K') // white bishop
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

int King::move(const std::string& source, const std::string& destination, Board& board)
{
    // Calculate differences in ranks and files
    int fileDiff = source[0] - destination[0];
    int rankDiff = source[1] - destination[1];

    // king can move at most one square in any direction
    if ((fileDiff > 1 || fileDiff < -1) || (rankDiff > 1 || rankDiff < -1))
    {
        return 6;
    }

    return Piece::move(source, destination, board);
}
