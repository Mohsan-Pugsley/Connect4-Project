#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(){
    playerOption = 0;
    boardRows = 0;
    boardColumns = 0;
}

Menu::displayMenu(){
    // display menu
    int playerOption=0;
    cout << "\t\tWelcome to Connect 4!\n\n";
    cout << "Please Select a Player Option" << endl;
    cout << "1. Person vs. Person" << endl;
    cout << "2. Person vs. Computer" << endl;
}

Menu::setPlayerOption(int newPlayerOption){
    cout << "Enter the number for the corresponding option above: " << endl;
    cin >> playerOption;

    playerOption = newPlayerOption;
}

Menu::getPlayerOption(){
    return newPlayerOption;
}





