#ifndef ROOM
#define ROOM

#include "entity.h"
#include "character.h"
#include "monster.h"
#include "item.h"

class Room {
    private:
        Item* item;
        int roomNumber;
        int statsMultiplier;
        bool hasVisited;
    public:
        Monster* roomMonster;
        Room(int roomNum);
        ~Room();
        void outputRoomDescription(); 
        void fightScreen();
        int getRoomNumber();
        Item* getItem();
        bool visited();
        void setVisited(bool);
};

#endif