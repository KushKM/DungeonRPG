#ifndef ENTITY
#define ENTITY 

class Entity {
    private:
        double health;
        double damage;
    public:
        void attackEnemy(Entity*);
        void takeDamage(int);
};
#endif