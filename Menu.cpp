#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(){
    playerOption = 0;

}


Menu::displayMenu(){
    // display menu
    cout << "\t\tWelcome to Connect 4!\n\n";
    cout << "Please Select a Player Option" << endl;
    cout << "1. Person vs. Person" << endl;
    cout << "2. Person vs. Computer" << endl;
    cout << "Enter the number for the corresponding option above: " << endl;
    cin >> playerOption;

    // respong to user's choice
    if(playerOption == 1){
        cout << "You have selected a Person opponent" << endl;
        // .playGame()
    }
    else if(playerOption == 2){
        cout << "You have selected a Computer opponent" << endl;
        // .playGame()
    }
    else{
        cout << "Please enter a valid option" << endl;
    }
}