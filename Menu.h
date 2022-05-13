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
        void setPlayerOption(); // Sets the player option
        int getPlayerOption(); // Returns the player option
        void displayPlayerOption();
        void displayBoardRows();
        void displayBoardColumns();
        void setBoardRows(); // 
        int getBoardRows();
        void setBoardColumns();
        int getBoardColumns(); 
};

#endif
