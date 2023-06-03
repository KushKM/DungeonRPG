//IDEAS FOR WIZARD
//High Damage Low Health Medium Speed
//Attacks have chance to do large amounts of damage

#include <iostream>

#include "wizard.h"

using namespace std;

Wizard::Wizard(){
    this->health = 20.0;
    this->damage = 20.0;
    this->currency = 10;
    this->speed = 5;
}

void Wizard::attackEnemy(Entity* e){
    int damageCalc = rand() % 9 + 1;
    if(damageCalc < 4){
        this->damage = 35;
    }
    e->takeDamage(getDamage());
}