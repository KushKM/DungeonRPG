#ifndef CHARACTER
#define CHARACTER

#include "entity.h"
#include "item.h"
#include <vector>



class Character : public Entity {
    private:
        double health;
        double damage;
        int currency;
        int speed;
        vector<Item*> inventory; 
    public:
        Character();
        Character(double h, double d, int c, int s);
        bool attemptRun();
        int getCurrency();
        void addCurrency(int amount); 
        void addItemToInventory(Item*); 
        void listInventory();
        void useItemFromInventory(int index);
        //virtual void reset_values() = 0; 
};

#endif