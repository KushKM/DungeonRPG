#include <iostream>
#include "monster.h"
#include "character.h"
#include "item.h"
#include <cstdlib>
using namespace std;


Monster::Monster() : Entity(), item(nullptr){}

Monster::Monster(double h, double d, Item* i, int s) : Entity(h, d), item(i), speed(s){}

Monster::~Monster() { 
    if(item != nullptr){
        delete item;
    }
}

int Monster::getSpeed(){ return speed; }
void Monster::printMonsterDescription(){
    cout << "           Monster health: " << getHealth() << endl;
}

// bool Monster::checkIfCurrency(Item* item){
//     return if(item->currencyPack());
// }

void Monster::monsterItemDrop(Character* player){
    /*int dropChance = rand() % 100 + 1;
    if(dropChance <= 30) {  
        item = new healthPack("Health Pack", 20);
        cout << "Monster dropped a health pack." << endl;
        cin.ignore();
        player->addItemToInventory(item);
    } 
    else if(dropChance > 30 && dropChance <= 60){  
        int currencyAmount = rand() % 50 + 1;  
        cout << "The monster dropped a currency pack." << endl;
        player->addCurrency(currencyAmount);
    }
    else if(dropChance > 60 && dropChance <= 70){
        item = new damageBooster("Damage Booster");
        cout << "Monster dropped a health pack." << endl; 
        cin.ignore();
        player->addItemToInventory(item); 
    }
    else{
        item = new Shield("Shield"); 
        cout << "Monster dropped a shield." << endl; 
        cin.ignore(); 
        player->equipShield(); 
    }*/
    /*if(checkIfCurrency(item)){
        player->addCurrency(getCurrency());
    }
    else if()
    else{
        player->addItemToInventory(item); 
    }*/
    player->addItemToInventory(item);
}
