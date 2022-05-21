#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(){
    // Initialise variables
    playerOption = 0;
    boardRows = 0;
    boardColumns = 0;
}

void Menu::displayMenu(){
    // Display menu options
    cout << "\t\tWelcome to Connect 4!\n\n";
    cout << "Please Select a Player Option" << endl;
    cout << "1. Person vs. Person" << endl;
    cout << "2. Person vs. Computer" << endl;
}

void Menu::setPlayerOption(){
    // User inputs player option
    cout<<"Enter the number for the corresponding option above: " << endl;
    cin>>playerOption;

    // Validate input 
    switch(playerOption){
        case 1:
            cout << "You picked a Person Opponent" << endl;
            break;
        case 2:
            cout << "You picked a Computer Opponent" << endl;
            break;
        default: 
            while((playerOption != 1) && (playerOption != 2)){
            cout << "Your choice is invalid" << endl;
            cout<<"Enter the number for the corresponding option above: " << endl;
            cin>>playerOption;
            if(playerOption == 1){
                cout << "You picked a Person Opponent" << endl;
            }
            else if(playerOption == 2){
                cout << "You picked a Computer Opponent" << endl;
            }
        }
            break;
    }
}

int Menu::getPlayerOption(){
    return playerOption;
}

void Menu::setBoardRows(){
    // User inputs and stores rows
    cout<<"Enter number of rows (min:4, max:8): ";
    cin>>boardRows; 
    // Validate input
    while ((boardRows < 4) || (boardRows > 8)){
        cout << "You have entered a number outside the range [4,8]. Please try again!: ";
        cin>>boardRows; 
    }
}

int Menu::getBoardRows(){
    return boardRows;  
}

void Menu::setBoardColumns(){
    // User inputs and stores columns
    cout<<"Enter number of columns (min:4, max:8): ";
    cin>>boardColumns;   
    // Validate input
    while ((boardColumns < 4) || (boardColumns > 8)){
        cout<<"You have entered a number outside the range [4,8]. Please try again!: ";
        cin>>boardColumns; 
    }
}

int Menu::getBoardColumns(){
    return boardColumns;  
}


