#ifndef PERSON_H
#define PERSON_H
#include "Player.h"
#include <string>

class Person : public Player{
    public:
        Player(Board& board,char& piece);
        virtual int GetMove();
};

#endif