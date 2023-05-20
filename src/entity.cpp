#include "entity.h"

#include <iostream>
using namespace std;

void Entity::takeDamage(int dmg) {
    this->health = this->health - dmg;
}