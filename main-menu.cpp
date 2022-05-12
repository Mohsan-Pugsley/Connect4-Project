#include "Menu.h"
#include <iostream>
using namespace std;

int main(){
    Menu m;
    m.displayMenu();
    m.setPlayerOption(0);
    m.getPlayerOption();
    m.setBoardRows(0);
    m.getBoardRows();
    m.setBoardColumns(0);
    m.getBoardColumns();
    m.displayPlayerOption();
    m.displayBoardRows();
    m.displayBoardColumns();
    return 0;
}