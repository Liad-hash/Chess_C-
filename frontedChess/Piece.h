#ifndef PIECE_H
#define PIECE_H

#include <string>

#define BLACK 1
#define WHITE -1

class Board;

class Piece
{
private:
    int activeSquareTests(const std::string& activePosition);
    int squareMoveTests(const std::string& squareMove);

protected:
    char sighted; // Symbol for color and piece type
    int turn; // 0 for white, 1 for black
    int color;

public:
    virtual ~Piece() = 0;
    virtual int move(const std::string& activePosition, const std::string& squareMove, Board& board) = 0; // virtual move
    char getSighted() const; // Getter for sighted
};

#endif
