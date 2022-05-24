#ifndef MENU_H
#define MENU_H
#include <string>
using namespace std;

// MENU: First stage of game. User interacts through inputting player option, and board size.
class Menu{
    int playerOption;
    int boardRows;
    int boardColumns;
    public:
        Menu(); // Default constructor
        void displayMenu(); // Displays the main menu
        void setPlayerOption(); // Sets the player option
        int getPlayerOption(); // Returns the player option
        void setBoardRows(); // User inputs number of board rows
        int getBoardRows(); // Returns the number of board rows
        void setBoardColumns(); // User inputs number of board columns
        int getBoardColumns(); // Returns the number of board columns
};

#endif