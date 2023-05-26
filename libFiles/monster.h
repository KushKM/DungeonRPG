#ifndef MONSTER
#define MONSTER 

#include "entity.h"
#include "character.h"
#include "item.h"

class Monster : public Entity {
    private:
        double health;
        double damage;
        Item* item;
    public:
        Monster();
        Monster(double h, double d, Item* i);
        void printMonsterDescription();
};
#endif