#include "game.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <vector>
using namespace std;

void printClassesIntro();
void printMainMenu();

Game::Game(){
    srand(time(NULL));
    //this value we will ask the user later
}

Game::~Game(){
    cout << "Game over...\n";
    for(int i = 0; i < dungeonRooms.size(); i++){
        delete dungeonRooms.at(i);
    }
}

//will print and ask for menuoptions (DONE)
void Game::mainMenuOptions() {
    printMainMenu();

    int choice = -1;
    while(!(choice >= 1 && choice <= 3)) {
        cin >> choice;
        if(choice >= 4 || choice <= 0){
            cout << "Invalid Choice. Try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    cout << endl;
    switch(choice) {
        case 1: 
            startDungeonRun();
            break;
        case 2: 
            displayShop();
            break;
        case 3: 
            return; //quit game, used number 0 so it doesnst get pressed by accident
            break;
    }
}

//will present user to choose a class on game start (DONE)
void Game::createCharacter() {
    printClassesIntro();
    
    int choice = -1;
    while(!(choice >= 1 && choice <= 4)) { 
        cin >> choice;
        if(choice >= 5 || choice <= 0){
            cout << "Invalid choice. Try again: "; 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            continue; 
        }
    }

    cout << "   You chose the ";
    switch(choice) {
        case 1:
            cout << "Wizard." << endl;
            this->player = new Wizard();
            break;
        case 2:
            cout << "Rogue." << endl;
            this->player = new Rogue();
            break;
        case 3:
            cout << "Warrior." << endl;
            this->player = new Warrior();
            break;
        case 4:
            cout << "Cleric." << endl;
            this->player = new Cleric();
            break;
    }
}

//Function that starts a run by "traveling to dungeon..."
void Game::startDungeonRun() {
    cout << endl << "Traveling to dungeon..." << endl;
    cin.ignore(); cin.ignore(); 
    
    currRoom->outputRoomDescription();

    bool isInDungeon = true;
    string input;
    while(isInDungeon) {
        currRoom->fightScreen();
        cout << "Player health: " << player->getHealth() << endl;
        cin.ignore();

        cout << "Type 'quit' to end program(dev note) Run or Fight or Move on(if all monsters dead)? (r/f/m): ";
        cin >> input;
        cout << endl;
        if(input == "quit"){
            break;
        }
        if(currRoom->roomMonster == nullptr && (input == "move" || input == "m")){
            changeRooms(0);
        }
        if(input == "r" || input == "run") {
            if(player->attemptRun() == true){
                changeRooms(1);
            }
            if(player->getHealth() <= 0){
                onDeath();
                break;
            }
        }
        if(input == "f" || input == "fight") {
            if(currRoom->roomMonster != nullptr){
                player->attackEnemy(currRoom->roomMonster);
                if(currRoom->roomMonster->getHealth() <= 0){
                    currRoom->roomMonster->monsterItemDrop(player); 
                    player->listInventory(); 
                    currRoom->roomMonster = nullptr; 
                    changeRooms(0);
                }
                else{
                    currRoom->roomMonster->attackEnemy(player);
                    if(player->getHealth() <= 0){
                        onDeath();
                        break;
                    }
                }
            }
            else cout << "Doesn't exist\n";
        }
    }
    
}

void Game::createDungeon(int totalSize){
    totalDungeonSize = totalSize;
    //first part, create room matrix
    int length = (int)(sqrt(totalSize));
    for(int i = 0; i < length; i++){
        for(int k = 0; k < length; k++){
            int randNum = (rand() % 4) + 1;
            //is the room on the far right in the middle
            if(i == length / 2 && k == length - 1){
                randNum = 5;
            }
            Room* newRoom = new Room(randNum);
            dungeonRooms.push_back(newRoom);
        }
    }
    roomIndex = (length * (length / 2)) + 1;
    currRoom = dungeonRooms.at(roomIndex);
}

void Game::changeRooms(int num){
    if(currRoom->getItem() != nullptr){
        player->addItemToInventory(currRoom->getItem());
    }
    vector<string> directions;
    string input;
    int sqr = (int)(sqrt(totalDungeonSize));
    if(roomIndex > sqr){
        directions.push_back("North");
    }
    if(roomIndex <= totalDungeonSize - sqr){
        directions.push_back("South");
    }
    if(roomIndex % sqr != 1){
        directions.push_back("West");
    }
    if(roomIndex % sqr != 0){
        directions.push_back("East");
    }
    if(num == 1){
        changeRoom(directions.at(0));
        currRoom = dungeonRooms.at(roomIndex);
        currRoom->outputRoomDescription();
    }else{
        bool wasDirection = false;
        while(!wasDirection){
            cout << "Type 'quit' to leave choice(dev note) Which way would you like to go? You can go ";
            for(int i = 0; i < directions.size(); i++){
                cout << directions.at(i);
                if(i < directions.size() - 1){
                    cout << ", ";
                }
            }
            cout << endl;
            cin >> input;
            if(input == "quit"){
                break;
            }
            for(int i = 0; i < directions.size(); i++){
                if(input == directions.at(i)){
                    wasDirection = true;
                    changeRoom(input);
                    currRoom = dungeonRooms.at(roomIndex);
                    currRoom->outputRoomDescription();
                    break;
                }
            }
        }
    }
}

void Game::changeRoom(string& newRoom){
    if(newRoom == "East"){
        roomIndex++;
    }
    if(newRoom == "North"){
        roomIndex -= (int)(sqrt(totalDungeonSize));
    }
    if(newRoom == "South"){
        roomIndex += (int)(sqrt(totalDungeonSize));
    }
    if(newRoom == "West"){
        roomIndex--;
    }
}

//ends the run if player dies (SEMI-DONE, needs better description)
void Game::onDeath() {
    cout << "You died" << endl;
    cout << "You beat " << roomNumber << " rooms." << endl;
    cout << "Your currency: " << player->getCurrency() << endl << endl;
    cin.ignore(); cin.ignore();
    mainMenuOptions();
}

//ends the run if player wins (SEMI-DONE, needs better description)
void Game::onVictory() {
    cout << "You won" << endl;
    cout << "Your currency: " << player->getCurrency() << endl << endl;
    cin.ignore(); cin.ignore();
    mainMenuOptions();
}

//displays the shop
void Game::displayShop() {
    cout << "Entering the shop.." << endl;
    //shop->displayItems(); 
    cin.ignore(); cin.ignore();
    mainMenuOptions();
}

//Helper function to print out the class infos (DONE)
void printClassesIntro() {
    ifstream file("helperFiles/classChoice.txt");
    if(file.is_open()) cout << file.rdbuf();
    file.close();
}

void printMainMenu() {
    ifstream file("helperFiles/mainMenu.txt");
    if(file.is_open()) cout << file.rdbuf();

    cout << endl;
    file.close();
}

int Game::getRoomIndex(){
    return roomIndex;
}