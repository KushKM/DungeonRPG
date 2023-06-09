#ifndef GAME
#define GAME

#include "character.h"
#include "monster.h"
#include "rogue.h"
#include "warrior.h"
#include "wizard.h"
#include "cleric.h"
#include "room.h"
#include "item.h"
#include "output.h"
#include <vector>

class Game {
    private:
        Character* player;
        Room* currRoom;
        int totalDungeonSize;
        int roomNumber = 0;
        vector<Room*> dungeonRooms;
        int roomIndex;

        MenuOutput outputMenu;
        ClassIntroOutput outputClassIntro;
        ShopOutput outputShop;
    public: 
        Game();
        ~Game();
        void deleteLevel();
        void mainMenuOptions();
        void createCharacter();
        void startDungeonRun();
        void onVictory();
        void onDeath();
        void displayShop();
        void createDungeon(int);
        void changeRooms(int);
        void changeRoom(std::string&);

        //test functions
        int getRoomIndex();

};

#endif