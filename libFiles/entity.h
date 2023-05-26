#ifndef ENTITY
#define ENTITY 

class Entity {
    private:
        double health;
        double damage;
        int currency;
    public:
        Entity();
        //health, damage. May add speed later
        Entity(double, double);
        void attackEnemy(Entity*);
        void takeDamage(int);
        int getCurrency();
        double getHealth();
        double getDamage();
};
#endif