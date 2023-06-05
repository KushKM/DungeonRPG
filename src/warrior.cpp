#include <iostream>

#include "warrior.h"

using namespace std;

Warrior::Warrior() : Character(40.0, 20.0, 10, 1){}

void Warrior::attackEnemy(Entity* e){
    double damageCalc = 40 - this->health;
    damage += damageCalc/2;
    e->takeDamage(getDamage());
}
