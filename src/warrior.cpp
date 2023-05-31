#include <iostream>

#include "warrior.h"
#include "character.h"
#include "monster.h"
#include "item.h"

using namespace std;

Warrior::Warrior() : Character() {}

Warrior::Warrior(double h, double d, int c, int s) : Character(h, d, c, s) {}

//IDEAS FOR WARRIOR
//High Damage High Health Low Speed
//No special abilities