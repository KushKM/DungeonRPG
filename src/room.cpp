#include "room.h"
#include <iostream>
#include <string>

using namespace std;

Room::Room(int roomNumber){
    //For boss rooms multiply monster stats or something
    if(roomNumber % 5 == 0){

    } else {

    }
}

void Room::outputRoomDescription(){
    int roomChoice = rand() % 4 + 1;

    switch(roomChoice) {
        case 1 :
            cout << "You have entered a dimly lit room. There seems to be scratches littered across the wall, each as big as you are. The bones of a creature are scattered throughout the room. Judging by the size of the bones, the now dead creature was probably twice your size. You are in danger." << endl;
            break;
        case 2 :
            cout << "You have entered a pitch black room. You can see nothing save for two glowing orbs in the distance and you can hear heaving breaths in the distance. As you hear footsteps approaching you must make a decision to fight or run." << endl;
            break;
        case 3 :
            cout << "A chest seems to be laying in a staight path ahead. It can't be that easy can it?" << endl;
            break;
        case 4 :
            cout << "There is a monster lying dead ahead. It has not spotted you yet so you have time to make a decision. But you must hurry, you do not know what this beast is capable of." << endl;
            break;
        case 5 :
            cout << "You have entered what seems to be an old bedroom. The skeleton of the previous occupant is lying on the bed, missing a few bones. There are teeth marks on the arms, and they seem to be recent. Whatever killed them is still here." << endl;
            break;
    }
}