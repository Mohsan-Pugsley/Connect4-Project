#include "Person.h"

Person::Person() {
}

void Person::move(){ // validate person input 
    cout<<"Person's move: ";
    cin>>playerInput;

    // need to aggregate Board for nCols to work
    /*while ((playerInput<nCols)||(playerInput>nCols)){
        cout << "Invalid. What column will you place your piece?: ";
        cin>>playerInput;
        cout << endl;
    } 
    */

}

int Person::getMove(){
    return playerInput;
}

Person::~Person(){
}

/*
int Person::personMove() {
    return 0;
}

void Person::move() {
    
}

Person::~Person() {

}
*/