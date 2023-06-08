#include <iostream>

#include "warrior.h"

using namespace std;

Warrior::Warrior() : Character(40.0, 20.0, 10, 1){}

void Warrior::attackEnemy(Entity* e){
    double damageCalc = (40 - this->getHealth()) / 2;
    this->setDamage(20.0 + damageCalc);
    e->takeDamage(this->getDamage());
}

void Warrior::resetValues() {
    health = 40;
    damage = 20;
    currency = 10;
    speed = 1;
}
