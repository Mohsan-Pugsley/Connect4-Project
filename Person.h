#ifndef PERSON_H
#define PERSON_H

#include "Player.h"

class Person : public Player{

    int personMove();

    public:
        Person();
        void move();
        ~Person();
    
};

#endif