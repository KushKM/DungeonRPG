#ifndef CLERIC
#define CLERIC

#include "character.h"

class Cleric : public Character {
    private:
        double health;
        double damage;
        int currency;
        int speed;
        vector<Item*> inventory; 
    public:
        Cleric();
        void takeDamage(int) override;
        void resetValues();
        
};


#endif