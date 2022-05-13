#include "Menu.h"
#include "Board.h"

#include <iostream>

int main(){

    Menu m;
    m.displayMenu();

    Board B;
    B.printEmptyBoard();
    B.printUpdatedBoard();
    return 0;
}