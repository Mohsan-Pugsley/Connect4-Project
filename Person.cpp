#include "Person.h"

Person::Person() {
}

void Person::setMenu(Menu m){
    this->m=m;

}

void Person::move(bool * full){
    cout<<"Person's move: ";
    cin>>playerInput;
    //need to aggregate Board for nCols to work
    while (checkCondition() == false){
        cout << "Invalid. What column will you place your piece?: ";
        cin>>playerInput;
        cout << endl;
    }
}

bool Person::checkCondition(){
    nCols = m.getBoardColumns();

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

Person::~Person(){
}
