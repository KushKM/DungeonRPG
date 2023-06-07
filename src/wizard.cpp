//IDEAS FOR WIZARD
//High Damage Low Health Medium Speed
//Attacks have chance to do large amounts of damage

#include <iostream>

#include "wizard.h"

using namespace std;

Wizard::Wizard() : Character(20.0, 20.0, 10, 5){}

void Wizard::attackEnemy(Entity* e){
    int damageCalc = rand() % 9 + 1;
    if(damageCalc < 4){
        e->takeDamage(35);
    } else {
        e->takeDamage(getDamage());
    }
    
}