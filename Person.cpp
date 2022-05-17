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
    while (checkCondition() == false){
        cout << "Invalid. What column will you place your token?: ";
        cin>>playerInput;
        cout << endl;
    }
}

bool Person::checkCondition(){
    // Sets the number of columns from person's input
    nCols = m.getBoardColumns();

    // Validate user input 
    if((playerInput<1)||(playerInput>nCols)){
        return false;
    }
    for(int i=0; i<m.getBoardRows(); i++){
        if(playerCheck[i][playerInput] == false){
            return true;
        }
    }
    return false;
}

int Person::getMove(){
    return playerInput;
}

