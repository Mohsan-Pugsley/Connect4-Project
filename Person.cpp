#include "Person.h"

Person::Person() {
}

void Person::move(){ // validate person input 
    cout<<"Person's move: ";
    cin>>playerInput;
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