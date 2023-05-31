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
    cout << "######## Escape failed ##########" << endl << endl; //stub
    cin.ignore(); cin.ignore();
}

void Character::addItemToInventory(Item* item){
    inventory.push_back(item);
    cout << "Added " << item->getName() << " to inventory." << endl; 
}

int Character::getCurrency()  { return currency; }

void Character::addCurrency(int amount){
    currency += amount; 
}

void Character::listInventory(){
    for(int i = 0; i < inventory.size(); i++){
        cout << i + 1 << ". " << inventory.at(i)->getName() << endl;
    }
}
