#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(){
    playerOption = 0;
    boardRows = 0;
    boardColumns = 0;
}

void Menu::displayMenu(){
    // display menu
    cout << "\t\tWelcome to Connect 4!\n\n";
    cout << "Please Select a Player Option" << endl;
    cout << "1. Person vs. Person" << endl;
    cout << "2. Person vs. Computer" << endl;
}

void Menu::setPlayerOption(){
    cout<<"Enter the number for the corresponding option above: " << endl;
    cin>>playerOption;
}

int Menu::getPlayerOption(){
    return playerOption;
}

void Menu::displayPlayerOption(){
    cout << playerOption << endl;
}

void Menu::setBoardRows(){
    //board size: input and store rows
    cout<<"Enter number of rows (min:4, max:8): ";
    cin>>boardRows; 
    // need to validate - cannot be less than 4 and cannot be greater than 8 
    if((boardRows < 4) && (boardRows > 8)){
        cout << "Please try again!: " << endl;
        cout<<"Enter number of rows (min:4, max:8): ";
        cin>>boardRows; 
    }
}

int Menu::getBoardRows(){
    return boardRows;  
}

void Menu::displayBoardRows(){
    cout << boardRows << endl;
}

void Menu::setBoardColumns(){
    //board size: input and store cols
    cout<<"Enter number of columns (min:4, max:8): ";
    cin>>boardColumns;   
    // need to validate - cannot be less than 4 and cannot be greater than 8
    if((boardColumns < 4) && (boardColumns > 8)){
        cout << "Please try again!: " << endl;
        cout<<"Enter number of columns (min:4, max:8): ";
        cin>>boardColumns; 
    }
    
}

void Menu::displayBoardColumns(){
    cout << boardColumns << endl;
}

int Menu::getBoardColumns(){
    return boardColumns;  
}


