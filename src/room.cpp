#include "room.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;


Room::Room(int roomNum){
    roomNumber = roomNum;
    roomMonster = nullptr;
    hasVisited = false;
    //For boss rooms multiply monster stats or something
    if(roomNumber == 5) {
        statsMultiplier = 3;
        Item* mItem = new currencyPack("Currency", 100);
        roomMonster = new Monster(150, 18, mItem, 11);
        item = nullptr;
    }else if(roomNumber == 1){
        Item* mItem = new healthPack("Health Pack", 30);
        roomMonster = new Monster(50, 6, mItem, 4);
        item = nullptr;
    }else if(roomNumber == 2){
        Item* mItem = new healthPack("Health Pack", 30);
        roomMonster = new Monster(50, 6, mItem, 2);
        item = nullptr;
    }else if(roomNumber == 3){
        //random item?
        item = new healthPack("Health Pack", 20);
        Item* mItem = new healthPack("Health Pack", 30);
        roomMonster = new Monster(50, 6, mItem, 0);
    }else if(roomNumber == 4){
        Item* mItem = new healthPack("Health Pack", 30);
        roomMonster = new Monster(50, 6, mItem, 7);
        item = nullptr;
    }
}

Room::~Room(){
    delete roomMonster;
    roomMonster = nullptr;
    if(item != nullptr){
        delete item;
    }
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
        if(roomMonster->getHealth() > 0){
            cout << "   %% There is a monster in front of you! %%\n";
            roomMonster->printMonsterDescription();
        }else{
            cout << "There appears to be no monster here.. maybe I killed it before?\n";
        }
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

void Room::setVisited(bool visited){
    this->hasVisited = visited;
}

bool Room::visited(){
    return hasVisited;
}