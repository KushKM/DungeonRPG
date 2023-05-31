//IDEAS FOR CLERIC
//Low Damage Medium Health Low Speed
//Heals itself every turn

#include <iostream>

#include "cleric.h"

using namespace std;

Cleric::Cleric(){
    this->health = 30.0;
    this->damage = 15.0;
    this->currency = 10;
    this->speed = 3;
}