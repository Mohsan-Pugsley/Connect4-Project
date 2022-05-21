#include "Menu.h"
#include <iostream>
using namespace std;

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
