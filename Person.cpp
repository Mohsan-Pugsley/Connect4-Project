#include "Person.h"

Person::Person(){
}

void Person::move(){
    //Menu m;
    cout<<"Person's move: ";
    cin>>playerInput;
    //nCols = m.getBoardColumns();

    // need to aggregate Board for nCols to work
    /*while ((playerInput<nCols)||(playerInput>nCols)){
        cout << "Invalid. What column will you place your piece?: ";
        cin>>playerInput;
        cout << endl;
    }*/
}

int Person::getMove(){
    return playerInput;
}

Person::~Person(){
}

