#ifndef PERSON_H
#define PERSON_H
#include "Player.h"
#include "Board.h"
#include <string>

class Person : public Player{
    public:
        Player(Board B);
        virtual int GetMove();
};

#endif