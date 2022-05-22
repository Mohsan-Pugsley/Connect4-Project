#ifndef PLAYER_H
#define PLAYER_H
#include "Menu.h"
#include <iostream>
using namespace std;

// PLAYER: base class that returns a player's move 
class Player{
    public:
        Player(); // Default constructor
        virtual void move(bool * full, int playerOption)=0; // Pure virtual function that will be implemented by the Person and Computer classes
        virtual int getMove(); // Returns the player's move
        void setPlayerCheck(bool ** playerCheck); // Sets the player's boardCheck
        int playerInput;
        bool ** playerCheck;  
};

#endif