#ifndef GAME_H
#define GAME_H
#include <iostream>

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
        void getState();
        void draw();
        void refresh();
        ~Game();
};

#endif