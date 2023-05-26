#include <iostream>
#include "character.h"
#include "monster.h"
#include "item.h"
using namespace std;

Character::Character() : Entity(), currency(0), speed(0){}

Character::Character(double h, double d, int c, int s) : Entity(h, d), currency(c), speed(s) {}

void Character::attemptRun() {
    //if fails ofc
    takeDamage(5);
    cout << "Escape failed" << endl; //stub
}

void Character::addItemToInventory(Item* item){
    inventory.push_back(item);
    cout << "Added " << item->getName() << " to inventory." << endl; 

    healthPack* h = dynamic_cast<healthPack*>(item);
    if(h != nullptr){
        int healthAmount = h->getHealthPack();
        cout << "Used a health pack. Restored " << healthAmount << " health." << endl;
    }
}

int Character::getCurrency() {return currency;}

void Character::addCurrency(int amount){
    currency += amount; 
}