#include <iostream>
#include "monster.h"
#include "character.h"
#include "item.h"
#include <cstdlib>
using namespace std;


Monster::Monster() : Entity(), item(nullptr){}

Monster::Monster(double h, double d, Item* i) : Entity(h, d), item(i){}

void Monster::printMonsterDescription(){
    cout << "Monster health: " << getHealth() << endl;
}


void Monster::monsterItemDrop(Character* player){
int dropChance = rand() % 100 + 1;
    if(dropChance <= 50) {  
        item = new healthPack("Health Pack", 20);
        cout << "Monster dropped a health pack." << endl;
        player->addItemToInventory(item);
        //player->useHealthPack(); 
       // cout << "You now have " << player->getHealth() << "coins." << endl; 
    } 
    else{  
        int currencyAmount = rand() % 50 + 1;  
        cout << "The monster dropped a currency pack." << endl;
        player->addCurrency(currencyAmount);
        //player->useCurrency(); 
        //cout << "You now have " << player->getCurrency() << "coins." << endl; 
    }
}
