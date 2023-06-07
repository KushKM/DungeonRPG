//IDEAS FOR ROGUE
//High Damage Low Health High Speed
//------------

#include <iostream>
#include "rogue.h"
using namespace std;

Rogue::Rogue() : Character(17.5, 25.0, 10, 10){}

void Rogue::takeDamage(int dmg){
    srand(time(NULL));
    int dodgeChance = rand() % 10 + 1;
    if(dodgeChance < 3) {
        cout << "       #### You dodged the attack! ####" << endl << endl; cin.ignore(); cin.ignore();
    } else {
        this->health = this->health - dmg;
    }
}

void Rogue::resetValues() {
    this->health = 17.5;
    this->damage = 25.0;
    this->currency = 10;
    this->speed = 10;
}