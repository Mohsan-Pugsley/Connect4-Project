#include "Person.h"
#include <iostream>

Person::Person(){
    // Initialise variable
    nCols = 0;
}

void Person::setMenu(Menu m){
    // Retrieve menu object
    this->m=m;
}

void Person::move(bool * full){
    // User inputs the column number to place token
    cout<<"Person's move: ";
    cin>>playerInput;
    // Loop to check valid input
    while (checkCondition(full) == false){
        cout << "Invalid. What column will you place your token?: ";
        cin>>playerInput;
        cout << endl;
    }
}

bool Person::checkCondition(bool * full){
    // Sets the number of columns from person's input
    nCols = m.getBoardColumns();

    // Validate user input
    // Range
    if((playerInput<1)||(playerInput>nCols)){
        return false;
    }

    // Column isn't full
    //cout << full[playerInput] << endl;
    //cout << playerInput << endl;
    if (full[playerInput-1] == false) {
        return false;
    }

    return true;
}

int Person::getMove(){
    return playerInput;
}

