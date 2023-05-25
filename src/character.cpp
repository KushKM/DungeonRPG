#include <iostream>
#include "character.h"
using namespace std;

Character::Character() {
    
}

Character::Character(double h, double d, int c, int s) {
    health = h;
    damage = d;
    currency = c;
    speed = s;
}

void Character::attackEnemy(Entity* e) {
    if(e->getHealth() == 0){
        currency += e->getCurrency();
    }
}
void Character::attemptRun() {
    cout << "Escape failed" << endl; //stub
}



int Character::getCurrency() {return currency;}