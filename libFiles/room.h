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
    public:
        Room(int roomNumber);
        void outputRoomDescription(); 
};

#endif