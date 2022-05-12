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

    return 0;
}