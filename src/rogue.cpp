//IDEAS FOR ROGUE
//High Damage Low Health High Speed
//------------

#include <iostream>
#include "rogue.h"
using namespace std;

Rogue::Rogue() : Character(17.5, 25.0, 10, 10){}

void Rogue::takeDamage(int dmg){
    int dodgeChance = rand() % 10 + 1;
    if(dodgeChance < 3) {
        cout << "       #### You dodged the attack! ####" << endl << endl; cin.ignore(); cin.ignore();
    } else {
        Entity::takeDamage(dmg);
    }
}

void Rogue::resetValues() {
    setHealth(17.5);
    setDamage(25.0);
    setSpeed(10);
}