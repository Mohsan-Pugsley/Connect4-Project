#ifndef MENU_H
#define MENU_H
#include <string>
using namespace std;

class Menu{
    int playerOption;
    int boardRows;
    int boardColumns;
    int *boardSize[2]; 
    public:
        Menu(); // Constructs
        void displayMenu(); // Displays the main menu
        void setPlayerOption(int newPlayerOption); // Sets the player option
        int getPlayerOption(); // Returns the player option
        void setBoardSize(int newBoardRows, int newBoardColumns);
        int getBoardSize(); // Returns the number of rows
        ~Menu();
};

#endif
