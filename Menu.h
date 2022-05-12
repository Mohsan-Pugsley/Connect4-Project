#ifndef MENU_H
#define MENU_H
#include <string>
using namespace std;

class Menu{
    int playerOption;
    int boardRows;
    int boardColumns;
    public:
        Menu(); // Constructs
        void displayMenu(); // Displays the main menu
        void setPlayerOption(int newPlayerOption); // Sets the player option
        int getPlayerOption(); // Returns the player option
        void setBoardSize(int newBoardRows, int newBoardColumns);
        int getBoardRows(); // Returns the number of rows
        void setBoardColumns(int newBoardColumns); // Sets the number of columns from user
        int getBoardColumns(); // Returns the number of columns
        ~Menu();
};

#endif
