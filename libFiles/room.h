#ifndef ROOM
#define ROOM

#include "libFiles/entity.h"
#include "libFiles/character.h"
#include "libFiles/monster.h"
#include "libFiles/item.h"

class Room {
    private:
     Monster* monster;
     Item item;
    
    public:
     Room(int roomNumber);
     void outputRoomDescription();
     
};

#endif