#ifndef WIZARD
#define WIZARD

#include "character.h"

class Wizard : public Character {
    private:
        double health;
        double damage;
        int currency;
        int speed;
        vector<Item*> inventory; 
    public:
        Wizard();
        
};


#endif