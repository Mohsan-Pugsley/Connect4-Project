#ifndef COMPUTER_H
#define COMPUTER_H
#include "Board.h"
#include "Player.h"

class Computer : public Player {
    public:
        Computer(Board& aBoard);
        virtual int GetMove();
};

#endif