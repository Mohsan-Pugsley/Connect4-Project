#ifndef PERSON_H
#define PERSON_H

#include "Player.h"
#include "Menu.h"

class Person : public Player{

    //int nCols;
    int nCols = 0;

    public:

        Person();
        ~Person();
        void setCols(int nCols);
        void move(bool * full);
        int getMove();
        Menu m;
        void setMenu(Menu m);
        bool checkCondition();

};

#endif