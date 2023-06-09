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
        int getSpeed();
        int getCurrency();
        void addCurrency(int amount); 
        void addItemToInventory(Item*); 
        void listInventory();
<<<<<<< HEAD
<<<<<<< HEAD
        void useItemFromInventory(int index);
        //virtual void reset_values() = 0; 
=======
        virtual void resetValues() = 0;
>>>>>>> 41c710bf1a57ea0c2688a1d2a6af7c8b4725b1cc
=======
        void useItemFromInventory(int index);
        virtual void resetValues() = 0;
>>>>>>> a56e62d69e3e788bc5c3ae708fb8ed1e1071a180
};

#endif