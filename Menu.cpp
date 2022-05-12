#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(){
    playerOption = 0;
    boardRows = 0;
    boardColumns = 0;
    boardSize = new int[boardRows, boardColumns];
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
    return PlayerOption;
}

Menu::setBoardSize(int newBoardRows, int newBoardColumns){
    if (PlayerOption==1){
        //board size: input and store rows/cols
        int nRows;
        cout<<"Enter number of rows: ";
        cin>>nRows;

        int nCols;
        cout<<"Enter number of columns: ";
        cin>>nCols;
    }
    else if(PlayerOption == 2){
        cout << "You have selected a Computer opponent" << endl;
    }
    else{
        cout << "Please enter a valid option" << endl;
    }

    
    


}

Menu::getBoardSize(){
    return boardSize;
    
}





