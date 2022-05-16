#include "Person.h"

Person::Person() {
}

void Person::move(){
    cout<<"Person's move: ";
    cin>>playerInput;
}

int Person::getMove(){
    return playerInput;
}

Person::~Person(){
}
