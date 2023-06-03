#ifndef ROGUE
#define ROGUE

#include "character.h"

class Rogue : public Character {
    private:
        double health;
        double damage;
        int currency;
        int speed;
        vector<Item*> inventory; 
    public:
        Rogue();
        void takeDamage(int) override;
        
};


#endif