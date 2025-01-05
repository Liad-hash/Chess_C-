#ifndef KNIGHT_H
#define KNIGHT_H

#include "board.h"

class Knight : public Piece
{
public:
    Knight(char symbol, int color);
    int move(const std::string& source, const std::string& destination, Board& board);
};

#endif
