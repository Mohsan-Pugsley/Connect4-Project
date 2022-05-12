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
    if (playerOption==1){
        //board size: input and store rows
        int newBoardRows;
        cout<<"Enter number of rows (min:4, max:8): ";
        cin>>newBoardRows;   
    }
    boardRows = newBoardRows;
}

int Menu::getBoardRows(){
    return boardRows;  
}

void Menu::setBoardColumns(int newBoardColumns){
    if (PlayerOption==1){
        //board size: input and store cols
        int newBoardColumns;
        cout<<"Enter number of columns (min:4, max:8): ";
        cin>>newBoardColumns;   
    }
    boardColumns = newBoardColumns;
}

int Menu::getBoardColumns(){
    return boardColumns;  
}






