#ifndef COMPUTER_H
#define COMPUTER_H
#include "Board.h"
#include "Menu.h"
#include "Player.h"
#include <string>

// COMPUTER: generates a random column for a token to be placed in
class Computer : public Player{
    private:
        int colCount;
        int lastMoveCol;
        int rowCount;
    public:
        Computer(); // Default constructor
        void setCols(int cols); // Sets the number of columns
        void setRows(int cols); // Sets the number of rows
        void move(bool *full); // Sets the computer's move
        int getMove(); // Returns the move
        void setMenu(Menu m); // Sets the Menu object
        bool checkCondition(bool * full); // Checks if valid input
        Menu m;

};

#endif