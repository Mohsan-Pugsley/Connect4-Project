#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"
#include <string>

class Computer {// : public Player {
    private:
        int colCount;
        int lastMoveCol;
    public:
        Computer();
        void move();
        void computeTurn();
        int getTurn();
        ~Computer();
};

#endif