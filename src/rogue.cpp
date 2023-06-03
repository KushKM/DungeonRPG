//IDEAS FOR ROGUE
//High Damage Low Health High Speed
//------------

#include <iostream>

#include "rogue.h"

using namespace std;

Rogue::Rogue(){
    this->health = 17.5;
    this->damage = 25.0;
    this->currency = 10;
    this->speed = 10;
}

void Rogue::takeDamage(int dmg){
    int dodgeChance = rand() % 10 + 1;
    if(dodgeChance < 3){
        //DISPLAY THAT THEY DODGED THE ATTACK
    } else {
        this->health = this->health - dmg;
    }
}