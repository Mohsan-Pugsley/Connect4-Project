#include "Person.h"
#include <iostream>
#include <string>
#include <limits>

Person::Person(){
    // Initialise variables
    nCols = 0;
    playerTracker=0;
}

void Person::setMenu(Menu m){
    // Retrieve menu object
    this->m=m;
}

void Person::move(bool * full, int playerOption){
    if (playerOption==1){
        //alternates player 1 and player 2
        playerTracker=playerTracker+1;
        
        if(playerTracker==3){
            playerTracker=playerTracker-2;
        }

        // User inputs the column number to place token
        cout<<"Person "<<playerTracker<<"'s move (enter column number): ";
        cin>>playerInput;
        cout << endl;

        // Loop to check for valid integer inputs within board
        while (playerInput<1||playerInput>m.getBoardColumns()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout << "Invalid input. Please input a column number between 1 and "<< m.getBoardColumns()<<": ";
            cin>>playerInput;
            cout << endl;
        }

        //Loop to check for valid inputs when column is full
        while (checkCondition(full) == false){
            //ignore input if its not inside the board or if its a non-integer input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout << "Invalid input. Column "<<playerInput<< " is full. Try again: ";
            cin>>playerInput;
            cout << endl;
        }

    } else if (playerOption==2){
        //person's turn
        playerTracker=1;

        cout<<"Your turn (enter column number): ";
        cin>>playerInput;

        // Loop to check for valid integer inputs within board
        while (playerInput<1||playerInput>m.getBoardColumns()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout << "Invalid input. Please input a column number between 1 and "<< m.getBoardColumns()<<": ";
            cin>>playerInput;
            cout << endl;
        }

        //Loop to check for valid inputs when column is full
        while (checkCondition(full) == false){
            //ignore input if its not inside the board or if its a non-integer input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout << "Invalid input. Column "<<playerInput<< " is full. Try again: ";
            cin>>playerInput;
            cout << endl;
        }
    }
}

bool Person::checkCondition(bool *full){
    // Sets the number of columns from person's input
    nCols = m.getBoardColumns();

    // Validate user input
    // Range
    if((playerInput<1)||(playerInput>nCols)){
        return false;
    }
    // Column isn't full
    if (full[playerInput-1] == false) {
        return false;
    }

    return true;
}

int Person::getMove(){
    return playerInput;
}