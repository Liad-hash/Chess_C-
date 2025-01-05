#ifndef KING_H
#define KING_H

#include "Board.h"

class King : public Piece
{
public:
    King(char symbol, int color);
    int move(const std::string& source, const std::string& destination, Board& board);

};

#endif
