#ifndef MONSTER
#define MONSTER 

#include "entity.h"
#include "item.h"

class Character; 

class Monster : public Entity {
    private:
        double health;
        double damage;
        Item* item;
    public:
        Monster();
        ~Monster();
        Monster(double h, double d, Item* i);
        //bool checkIfCurrency(Item* ); 
        void printMonsterDescription();
        void monsterItemDrop(Character* ); 
};

#endif