#ifndef GAME
#define GAME

#include "character.h"
#include "monster.h"
#include "room.h"

class Game {
    private:
        Character* player;
        Room* currRoom;
        int roomNumber = 0;
    public: 
        Game() {}
        void mainMenuOptions();
        void createCharacter();
        void startDungeonRun();
        void onVictory();
        void onDeath();
        void displayShop();
        void newRoom();
};

#endif