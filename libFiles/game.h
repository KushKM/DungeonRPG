#ifndef GAME
#define GAME

#include "character.h"
#include "monster.h"
#include "room.h"
#include "item.h"

class Game {
    private:
        Character* player;
        Room* currRoom;
        int totalDungeonSize;
        int roomNumber = 0;
    public: 
        Game();
        ~Game();
        void mainMenuOptions();
        void createCharacter();
        void startDungeonRun();
        void onVictory();
        void onDeath();
        void displayShop();
        void createLevel(int);

};

#endif