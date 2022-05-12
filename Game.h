#include <iostream>
#include "Menu.h"

class Game {
    private:
        bool player1Won;
        bool player2Won;
        bool gameDraw;
        bool gameState;

        //Player player1;
        //Player player2;
        Menu menu;
        Board board;
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