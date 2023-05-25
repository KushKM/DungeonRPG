#include <iostream>
#include "monster.h"
using namespace std;


Monster::Monster() {
    
}

Monster::Monster(double h, double d, Item* i) {
    health = h;
    damage = d;
    item = i;
}

void Monster::attackEnemy(Entity* e) {
    
}

void Monster::printMonsterDescription(){
    cout << "MONSTER_INFO_HERE" <<endl;
}
