#ifndef GAME
#define GAME

#include "character.h"
#include "monster.h"
#include "room.h"

class Game {
    private:
        Character* player;
        Room* currRoom;
    public: 
        Game();
        void StartRun();
        void onDeath();
        void endRun();
        void displayShop();
        void createCharacter();
};

#endif