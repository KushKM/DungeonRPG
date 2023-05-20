#include <iostream>
#include "monster.h"
using namespace std;

Monster::Monster(double h, double d, Item i) {
    health = h;
    damage = d;
    item = i;
}

void Monster::attackEnemy(Entity* e) {
    
}

