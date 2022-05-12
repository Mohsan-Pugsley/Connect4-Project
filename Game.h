#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Menu.h"

class Game {
    private:
        bool player1Won;
        bool player2Won;
        bool gameDraw;
        Menu menu;
    public:
        Game();
        void initialize();
        void runGame();
        void setState();
        int getState();
        void draw();
        void refresh();
        ~Game();
};

#endif