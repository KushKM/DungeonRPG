#ifndef ENTITY
#define ENTITY 

class Entity {
    private:
        double health;
        double damage;
        int currency;
        bool hasShield;
    public:
        Entity();
        //health, damage. May add speed later
        Entity(double, double);
        virtual void attackEnemy(Entity*);
        virtual void takeDamage(int);
        void equipShield(); 
        bool hasShieldEquipped(); 
        void removeShield(); 
        int getCurrency();
        void setHealth(double );
        double getHealth();
        void setDamage(double ); 
        double getDamage();
};
#endif