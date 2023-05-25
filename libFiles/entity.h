#ifndef ENTITY
#define ENTITY 

class Entity {
    private:
        double health;
        double damage;
        int currency;
    public:
        void attackEnemy(Entity*);
        void takeDamage(int);
        int getCurrency();
        double getHealth();
};
#endif