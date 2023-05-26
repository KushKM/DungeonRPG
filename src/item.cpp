#include "item.h"
#include <iostream> 

using namespace std;

Item::Item() {}

Item::Item(string itemName, int healthAmount, int currencyAmount) {
    name = itemName;
    healthPack = healthAmount;
    currencyPack = currencyAmount;
}

/*class healthPack : public Item {
public:
    healthPack() : Item() {}
    healthPack(string itemName, int healthAmount) : Item(itemName, healthAmount, 0) {}
};

class currencyPack : public Item {
public:
    currencyPack() : Item() {}
    currencyPack(string itemName, int currencyAmount) : Item(itemName, 0, currencyAmount) {}
};*/

string Item::getName()      { return name; }
int Item::getHealthPack()   { return healthPack; }
int Item::getCurrency()     { return currencyPack; }
void Item::useHealthPack() {
    cout << "Using a health pack. Restoring " << healthPack << " health." << endl; 
    //implement health addition
}
void Item::useCurrency() {
    cout << "Gained a currency pack. Gaining " << currencyPack << " currency." << endl; 
    //implement currency addition
} 