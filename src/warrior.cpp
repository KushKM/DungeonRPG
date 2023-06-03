#include <iostream>

#include "warrior.h"

using namespace std;

Warrior::Warrior(){
    this->health = 40.0;
    this->damage = 20.0;
    this->currency = 10;
    this->speed = 1;
}

void Warrior::attackEnemy(Entity* e){
    double damageCalc = 40 - this->health;
    damage += damageCalc/2;
    e->takeDamage(getDamage());
}
