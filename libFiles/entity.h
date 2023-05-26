#ifndef ENTITY
#define ENTITY 

class Entity {
    private:
        double health;
        double damage;
    public:
        Entity();
        //health, damage. May add speed later
        Entity(double, double);
        void attackEnemy(Entity*);
        void takeDamage(int);
        double getHealth();
        double getDamage();
};
#endif