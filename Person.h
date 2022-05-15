#ifndef PERSON_H
#define PERSON_H
#include "Player.h"
#include "Board.h"
#include <string>

class Person : public Player {
    public:
        //Player(Board B);
        //Person(Board B);
        Person(Board B):Player(B) {}; // compiler seems to want {} here? not too sure
        virtual int GetMove();
};

#endif