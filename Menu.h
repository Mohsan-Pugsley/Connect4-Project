#ifndef MENU_H
#define MENU_H
#include <string>
using namespace std;

class Menu{
    int playerOption;
    int boardRows;
    int boardColumns;
    public:
        Menu(); \\ Constructs
        void displayMenu(); \\ Displays the main menu
        void setboardRows(int newBoardRows); \\ Sets the number of rows from user 
        int getboardRows(); \\ Returns the number of rows
        void setboardColumns(int newBoardColumns); \\ Sets the number of columns from user
        int getboardColumns(); \\ Returns the number of columns
};

#endif