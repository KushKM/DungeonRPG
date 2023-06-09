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
<<<<<<< HEAD
        Monster(double h, double d, Item* i);
        //bool checkIfCurrency(Item* ); 
=======
        Monster(double h, double d, Item* i, int s);
        int getSpeed();
>>>>>>> 41c710bf1a57ea0c2688a1d2a6af7c8b4725b1cc
        void printMonsterDescription();
        void monsterItemDrop(Character* ); 
};

#endif