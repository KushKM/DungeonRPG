#include <iostream>
#include "monster.h"
using namespace std;


Monster::Monster() : Entity(), item(nullptr){}

Monster::Monster(double h, double d, Item* i) : Entity(h, d), item(i){}

void Monster::printMonsterDescription(){
    cout << "Monster health: " << getHealth() << endl;
}
