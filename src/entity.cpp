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
void Entity::setHealth(double s){
    health = s; 
}

double Entity::getHealth() {
    return this->health;
}

void Entity::setDamage(double d){
    damage = d; 
}

double Entity::getDamage(){
    return this->damage;
}

int Entity::getCurrency(){
    return this->currency;
}