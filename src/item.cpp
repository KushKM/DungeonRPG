#include "item.h"
using namespace std;

Item::Item() {

}

Item::Item(string itemName, int healthAmount, int currencyAmount) {
    name = itemName;
    healthPack = healthAmount;
    currencyPack = currencyAmount;
}

string Item::getName()      { return name; }
int Item::getHealthPack()   { return healthPack; }
int Item::getCurrency()     { return currencyPack; }
void Item::useHealthPack() {}
void Item::useCurrency() {} 