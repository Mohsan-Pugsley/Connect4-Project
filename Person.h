#ifndef PERSON_H
#define PERSON_H
#include "Player.h"
#include "Menu.h"

// PERSON: User can input a column to place their taken
class Person : public Player{
    int nCols;
    public:
        Person(); // Default constructor
        void move(bool *full); // Sets person's move
        int getMove(); // Returns the move
        void setMenu(Menu m); // Sets the Menu object
        bool checkCondition(); // Checks if valid input
        Menu m;
};

#endif