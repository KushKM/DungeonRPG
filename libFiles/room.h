#ifndef ROOM
#define ROOM

#include "entity.h"
#include "character.h"
#include "monster.h"
#include "item.h"

class Room {
    private:
        Monster* monster;
        Item item;
        int roomNumber;
    public:
        Room(int roomNum);
        void outputRoomDescription(); 
};

#endif