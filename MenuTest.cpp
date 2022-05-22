#include "Menu.h"
#include <iostream>
using namespace std;

// Menu Test: testing the Menu class to ensure that the user can input the playerOption, number of rows and number of columns
int main(){
    Menu menu;
    menu.displayMenu();
    menu.setPlayerOption();
    menu.getPlayerOption();
    // Check if prints the inputted option from the user
    cout << menu.getPlayerOption() << endl;

    menu.setBoardRows();
    menu.getBoardRows();
    // Check if prints the inputted number of rows from the user
    cout << menu.getBoardRows() << endl;

    menu.setBoardColumns();
    menu.getBoardColumns();
    // Check if prints the inputted number of columns from the user
    cout << menu.getBoardColumns() << endl;

    return 0;
}
