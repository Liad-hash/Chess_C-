#ifndef Queen_H
#define Queen_H

#include "board.h"

class Queen : public Piece
{
private:
    int previous_steps_rook(const std::string& source, const std::string& destination, Board& board);
    int previous_steps_bishop(const std::string& source, const std::string& destination, Board& board);
public:
    Queen(char symbol, int color);
    int move(const std::string& source, const std::string& destination, Board& board);
    
    int moveLikeRook(const std::string& source, const std::string& destination, Board& board);
    int moveLikeBishop(const std::string& source, const std::string& destination, Board& board);
};

#endif
