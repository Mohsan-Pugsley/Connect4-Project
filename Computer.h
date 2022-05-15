#ifndef COMPUTER_H
#define COMPUTER_H
#include "Board.h"
#include "Menu.h"
#include "Player.h"
#include <string>

class Computer : public Player {
    public:
        Computer(Board& aBoard, const char& piece);
        virtual int GetMove();
};

#endif