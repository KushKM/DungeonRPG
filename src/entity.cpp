#include "entity.h"

#include <iostream>
using namespace std;

Entity::Entity() : health(0), damage(0){}

Entity::Entity(double h, double d) : health(h), damage(d){}

void Entity::attackEnemy(Entity* e){
    e->takeDamage(getDamage());
}

void Entity::takeDamage(int dmg) {
    this->health = this->health - dmg;
}

double Entity::getHealth() {
    return this->health;
}

double Entity::getDamage(){
    return this->damage;
}