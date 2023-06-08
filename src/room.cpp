#include "room.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;


Room::Room(int roomNum){
    roomNumber = roomNum;
    roomMonster = nullptr;
    //For boss rooms multiply monster stats or something
    if(roomNumber == 5) {
        statsMultiplier = 3;
        Item* mItem = new damageBooster("Damage Booster");
        roomMonster = new Monster(150, 18, mItem);
        item = nullptr;
    }else if(roomNumber == 1){
        Item* mItem = new healthPack("Health Pack", 30);
        roomMonster = new Monster(50, 6, mItem);
        item = nullptr;
    }else if(roomNumber == 2){
        Item* mItem = new currencyPack("CurrencyPack", 100);
        roomMonster = new Monster(50, 6, mItem);
        item = nullptr;
    }else if(roomNumber == 3){
        // int dropChance = rand() % 100 + 1;
        // if(dropChance < 30){
        //     Item* mItem = new Shield("Shield"); 
        //     roomMonster = new Monster(50, 5, mItem);
        // }
        // else{
            Item* mItem = new healthPack("Health Pack", 30);
            roomMonster = new Monster(50, 6, mItem);
        //}
    }else if(roomNumber == 4){
        // int dropChance = rand() % 100 + 1;
        // if(dropChance > 30 && dropChance < 60){
        //     Item* mItem = new Shield("Shield"); 
        //     roomMonster = new Monster(50, 5, mItem);
        // }
        // else{
            Item* mItem = new healthPack("Health Pack", 30);
            roomMonster = new Monster(50, 6, mItem);
        }
}

Room::~Room(){
    delete roomMonster;
    delete item;
}

void Room::outputRoomDescription() {
    cout << "=========\n Room " << roomNumber << "\n=========" << endl;

    switch(roomNumber) {
        case 1 :
            cout << "You have entered a dimly lit room. There seems to be scratches littered across the wall, each as big as you are. The bones of a creature are scattered throughout the room. Judging by the size of the bones, the now dead creature was probably twice your size. You are in danger.";
            break;
        case 2 :
            cout << "You have entered a pitch black room. You can see nothing save for two glowing orbs in the distance and you can hear heaving breaths in the distance. As you hear footsteps approaching you must make a decision to fight or run.";
            break;
        case 3 :
            cout << "A chest seems to be laying in a staight path ahead. It can't be that easy can it?";
            break;
        case 4 :
            cout << "There is a monster lying dead ahead. It has not spotted you yet so you have time to make a decision. But you must hurry, you do not know what this beast is capable of.";
            break;
        case 5 :
            cout << "You have entered what seems to be an old bedroom. The skeleton of the previous occupant is lying on the bed, missing a few bones. There are teeth marks on the arms, and they seem to be recent. Whatever killed them is still here.";
            break;
    }
    cin.ignore();   
    cout << endl;
}

void Room::fightScreen() {
    if(roomMonster != nullptr){
        cout << "   %% There is a monster in front of you! %%\n";
        roomMonster->printMonsterDescription();
    }
}

int Room::getRoomNumber(){
    return roomNumber;
}

Item* Room::getItem(){
    if(item != nullptr){
        return item;
    }
    return nullptr;
}