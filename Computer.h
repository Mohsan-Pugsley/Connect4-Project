#ifndef COMPUTER_H
#define COMPUTER_H
#include "Board.h"
#include "Menu.h"
#include "Player.h"
#include <string>

class Computer : public Player {
    private:
        int colCount;
        int lastMoveCol;
    public:
        /*
        Computer();
        void move();
        void computeTurn();
        int getTurn();
        ~Computer();
        */

        Computer();
        void setCols(int cols);
        virtual void move();
        virtual int getMove();
        ~Computer();
};

#endif