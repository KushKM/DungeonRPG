#include "item.h"
#include "character.h"
#include <iostream> 
using namespace std;

Item::Item() {}

Item::Item(string itemName) : name(itemName) {
}

string Item::getName() { 
    return name;
}
