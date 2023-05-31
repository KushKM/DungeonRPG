#include <iostream>
#include "character.h"
#include "monster.h"
#include "item.h"
#include <cstdlib>
using namespace std;

Character::Character() : Entity(), currency(0), speed(0){}

Character::Character(double h, double d, int c, int s) : Entity(h, d), currency(c), speed(s) {}

void Character::attemptRun() {
    //if fails ofc
    int chance = rand() % 20;
    //25% chance for now :)
    if(chance < 5){
        //figure out what to do. what i was thinking was to make this a bool method and just check the chance and do everything else in game.cpp
    }else{
        takeDamage(5);
        cout << "########## Escape failed ##########" << endl << endl; //stub
        cin.ignore(); cin.ignore();
    }
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
