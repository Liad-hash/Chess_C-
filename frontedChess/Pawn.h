#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include "Board.h"

class Board;

class Pawn : public Piece
{
private:
    int move_Forward(const std::string& source, const std::string& destination, Board& board);
    int move_Diagonal(const std::string& source, const std::string& destination, Board& board);
public:
    Pawn(char symbol, int color);
    int move(const std::string& source, const std::string& destination, Board& board);
};

#endif
