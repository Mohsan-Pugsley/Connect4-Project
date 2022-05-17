#ifndef PLAYER_H
#define PLAYER_H
//#include "Person.h"
//#include "Computer.h"
#include "Menu.h"
#include <iostream>
using namespace std;

class Player{

    public:
        Player(); //constructor
        virtual ~Player();
        virtual void move(bool * full)=0;
        virtual int getMove();
        bool ** playerCheck;
        void setPlayerCheck(bool ** playerCheck);
        
        int playerInput;
        
};

#endif