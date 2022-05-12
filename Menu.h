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
<<<<<<< HEAD
        void setBoardSize(int newBoardRows, int newBoardColumns);
        int getBoardSize(); // Returns the board row and column
=======
        void setBoardRows(int newBoardRows); // 
        int getBoardRows();
        void setBoardColumns(int newBoardColumns);
        int getBoardColumns(); 
<<<<<<< HEAD
        //~Menu();
=======
>>>>>>> 46a7c3c4b6767d7b73b8e9786ccab8b36930e5c4
        ~Menu();
>>>>>>> a8a757264a200e96e30b17e1045de713ac3df645
};

#endif
