#include "Menu.h"
#include <iostream>
using namespace std;

// Testing the Menu class
int main(){
    Menu m;
    m.displayMenu();
    m.setPlayerOption();
    m.getPlayerOption();
    m.setBoardRows();
    m.getBoardRows();
    m.setBoardColumns();
    m.getBoardColumns();
    return 0;
}