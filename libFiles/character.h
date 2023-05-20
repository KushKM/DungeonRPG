#ifndef CHARACTER
#define CHARACTER

#include "entity.h"
#include "monster.h"

class Character : public Entity {
    private:
        double health;
        double damage;
        int currency;
        int speed;
    public:
        Character();
        Character(double h, double d, int c, int s);
        void attackEnemy(Entity* e);
        void attemptRun();
};

#endif