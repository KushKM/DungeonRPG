#ifndef WARRIOR
#define WARRIOR

#include "character.h"

class Warrior : public Character {
    private:
        double health;
        double damage;
        int currency;
        int speed;
        vector<Item*> inventory; 
    public:
        Warrior();
        void attackEnemy(Entity*) override;
};


#endif