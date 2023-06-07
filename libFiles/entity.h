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
        virtual void attackEnemy(Entity*);
        virtual void takeDamage(int);
        int getCurrency();
        void setHealth(double );
        double getHealth();
        void setDamage(double ); 
        double getDamage();
};
#endif