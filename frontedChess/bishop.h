#ifndef BISHOP_H
#define BISHOP_H

#include "board.h"

class Bishop : public Piece
{
public:
    Bishop(char symbol, int color);
    int move(const std::string& source, const std::string& destination, Board& board);
    int previous_steps(const std::string& source, const std::string& destination, Board& board);
};

#endif
