//IDEAS FOR ROGUE
//High Damage Low Health High Speed
//------------

#include <iostream>

#include "rogue.h"

using namespace std;

Rogue::Rogue() : Character(17.5, 25.0, 10, 10){}

void Rogue::takeDamage(int dmg){
    int dodgeChance = rand() % 10 + 1;
    if(dodgeChance < 3){
        //DISPLAY THAT THEY DODGED THE ATTACK
    } else {
        this->health = this->health - dmg;
    }
}