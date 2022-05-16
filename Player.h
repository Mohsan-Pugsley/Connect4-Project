#ifndef PLAYER_H
#define PLAYER_H
#include "Menu.h"
#include <iostream>
using namespace std;

class Player{
    public:
        Player(); //constructor
        ~Player();
        virtual void move()=0;
        virtual int getMove();
        
        int playerInput;
               
};

#endif