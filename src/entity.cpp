#include "entity.h"

#include <iostream>
using namespace std;

void Entity::takeDamage(int dmg) {
    this->health = this->health - dmg;
}

int Entity::getCurrency(){
    return this->currency;
}

double Entity::getHealth(){
    return this->health;
}