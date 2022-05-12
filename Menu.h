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
        void setBoardRows(int newBoardRows); // 
        int getBoardRows();
        void setBoardColumns(int newBoardColumns);
        int getBoardColumns(); 
        ~Menu();
};

#endif
