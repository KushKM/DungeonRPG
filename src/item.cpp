#include "item.h"
#include <iostream> 

using namespace std;

Item::Item() {}

Item::Item(string itemName, int healthAmount, int currencyAmount) {
    name = itemName;
    healthPack = healthAmount;
    currencyPack = currencyAmount;
}

void Item::use() {
    cout << "Using " << getName() << endl;
}

string Item::getName()      { return name; }
int Item::getHealthPack()   { return healthPack; }
int Item::getCurrency()     { return currencyPack; }

void healthPack::use(){
    cout << "Using health pack. Restoring " << getHealthPack() << " health." << endl; 
}

void currencyPack::use(){
    cout << "Gained currency pack. Adding " << getCurrency() << " coins." << endl; 
}
