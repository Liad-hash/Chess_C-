#ifndef ROOK_H
#define ROOK_H

#include "board.h"

class Rook : public Piece
{
public:
    Rook(char symbol, int color);
    int move(const std::string& source, const std::string& destination, Board& board);
    int previous_steps(const std::string& source, const std::string& destination, Board& board);
};

#endif
