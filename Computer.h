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
        int rowCount;
    public:
        Computer();
        void setCols(int cols);
        void move(bool * full);
        int getMove();
        ~Computer();
        Menu m;
        void setMenu(Menu m);
        bool checkCondition();

};

#endif