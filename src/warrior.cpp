#include <iostream>

#include "warrior.h"

using namespace std;

Warrior::Warrior() : Character(40.0, 20.0, 10, 1){}

void Warrior::attackEnemy(Entity* e){
    double damageCalc = 40 - this->health;
    damage += damageCalc/2;
    e->takeDamage(getDamage());
}

void Warrior::resetValues() {
    health = 40;
    damage = 20;
    currency = 10;
    speed = 1;
}
