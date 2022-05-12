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

void Menu::setPlayerOption(int newPlayerOption){
    cout << "Enter the number for the corresponding option above: " << endl;
    cin >> playerOption;

    playerOption = newPlayerOption;
}

int Menu::getPlayerOption(){
    return playerOption;
}

void Menu::setBoardRows(int newBoardRows){
    //board size: input and store rows
    cout<<"Enter number of rows (min:4, max:8): ";
    cin>>newBoardRows; 
    // need to validate - cannot be less than 4 and cannot be greater than 8 
    if((newBoardRows >= 4) && (newBoardRows <= 8)){
        boardRows = newBoardRows;
    }
    else{
        cout << "Please try again!: " << endl;
        cout<<"Enter number of rows (min:4, max:8): ";
        cin>>newBoardRows; 
    }
}

int Menu::getBoardRows(){
    return boardRows;  
}

void Menu::setBoardColumns(int newBoardColumns){
    //board size: input and store cols
    cout<<"Enter number of columns (min:4, max:8): ";
    cin>>newBoardColumns;   
    // need to validate - cannot be less than 4 and cannot be greater than 8
    if((newBoardColumns >= 4) && (newBoardColumns <= 8)){
        boardColumns = newBoardColumns;
    }
    else{
        cout << "Please try again!: " << endl;
        cout<<"Enter number of columns (min:4, max:8): ";
        cin>>newBoardColumns; 
    }
    boardColumns = newBoardColumns;
}

int Menu::getBoardColumns(){
    return boardColumns;  
}



