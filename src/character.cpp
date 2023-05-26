#include <iostream>
#include "character.h"
using namespace std;

Character::Character() : Entity(), currency(0), speed(0){}

Character::Character(double h, double d, int c, int s) : Entity(h, d), currency(c), speed(s) {}

void Character::attemptRun() {
    //if fails ofc
    takeDamage(5);
    cout << "Escape failed" << endl; //stub
}

int Character::getCurrency() {return currency;}