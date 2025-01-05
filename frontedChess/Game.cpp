#include "Game.h"
#include <iostream>

Game::Game()
{
    Board board;
    std::string gameString = board.boardSTR();

    if (gameString[64] == '0')
    {
        this->bORw_turn = 0; // white start
    }
    else
    {
        this->bORw_turn = 1; // black start
    }
}

int Game::getturn()
{
    return bORw_turn;
}

void Game::switchTurn()
{
    if (bORw_turn == 0)
    {
        bORw_turn = 1; // Switch to black turn
    }
    else
    {
        bORw_turn = 0; // Switch to white turn
    }
}

int Game::update(Board& board, const std::string& from, const std::string& to)
{
    Piece* movingPiece = board.specificSquare(from[0], from[1]); // Source square
    if (!movingPiece)
    {
        std::cout << "Invalid move, no piece at the source square." << std::endl;
        return 2;
    }

    int turn;
    if (isupper(board.specificSquare(from[0], from[1])->getSighted()))
    {
        turn = 0; // White piece
    }
    else
    {
        turn = 1; // Black piece
    }

    int protocolGame;
    if (this->getturn() != turn)
    {
        protocolGame = 5; // Not Player's turn
    }
    else
    {
        protocolGame = movingPiece->move(from, to, board);
    }

    switch (protocolGame)
    {
    case 0:
        switchTurn();
        return 0;
    case 1:
        switchTurn();
        return 1;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    case 6:
        return 6;
    case 7:
        return 7;
    default:
        std::cout << "Unknown move error!" << std::endl;
        break;
    }
}
