#ifndef PLAYER_H
#define PLAYER_H
#include "Person.h"
#include "Computer.h"
#include "Board.h"
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class Player{
    public:
    Player(Board& board, char& piece);
    virtual int GetMove()=0;
    void SetPiece(char& piece);
    inline char GetPiece();
    char newPiece;
    Board newBoard;   
};

#endif