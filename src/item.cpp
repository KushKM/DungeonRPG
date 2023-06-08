#include "item.h"
#include "character.h"
#include <iostream> 

using namespace std;

Item::Item() {}

Item::Item(string itemName, int healthAmount, int currencyAmount) {
    name = itemName;
    healthPack = healthAmount;
    currencyPack = currencyAmount;
}

void Item::use(Character* player) {
    cout << "Using " << getName() << endl;
}

string Item::getName()      { return name; }
int Item::getHealthPack()   { return healthPack; }
int Item::getCurrency()     { return currencyPack; }

void healthPack::use(Character* player){
    //cout << "Using health pack. Restoring " << player->setHealth(player->getHealth() + getHealthPack()) << " health." << endl; 
}

void currencyPack::use(Character* player){
    //cout << "Gained currency pack. Adding " << player->addCurrency(getCurrency()) << " coins." << endl; 
}

void damageBooster::use(Character* player){
    //cout << "Using damage booster. Multiplying by 1.5x." << player->setDamage((player->getDamage() * 1.5)); 
}

void Shield::use(Character* player){
    player->equipShield(); 
}