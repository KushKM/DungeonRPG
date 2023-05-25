#ifndef ROOM
#define ROOM

#include "entity.h"
#include "character.h"
#include "monster.h"
#include "item.h"

class Room {
    private:
        Item item;
        int roomNumber;
        int statsMultiplier;
    public:
        Monster* roomMonster;
        Room(int roomNum);
        void outputRoomDescription(); 
        void fightScreen();
};

#endif