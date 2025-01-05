#ifndef GAME_H
#define GAME_H

#include <string>
#include "board.h"
#include "Piece.h"

class board;

class Game 
{
private:
    int bORw_turn = 0; // 0 for white, 1 for black

public:
    Game();
    int getturn();
    void switchTurn();
    int update(Board& board, const std::string& from, const std::string& to);

};

#endif
