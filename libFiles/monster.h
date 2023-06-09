#ifndef MONSTER
#define MONSTER 

#include "entity.h"
#include "item.h"

class Character; 

class Monster : public Entity {
    private:
        double health;
        double damage;
        int speed;
        Item* item;
    public:
        Monster();
        ~Monster();
        Monster(double h, double d, Item* i, int s);
        int getSpeed();
        void printMonsterDescription();
        void monsterItemDrop(Character* ); 
};

#endif