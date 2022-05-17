#ifndef PERSON_H
#define PERSON_H

#include "Player.h"
#include "Menu.h"

class Person : public Player{

    int nCols;

    public:

        Person();
        ~Person();
        virtual void move(bool * full);
        virtual int getMove();
        Menu m;
        void setMenu(Menu m);
        bool checkCondition();
        
};

#endif