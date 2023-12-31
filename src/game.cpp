#include "game.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <vector>
#include <string>
using namespace std;

Game::Game(){
    srand(time(NULL));
    player = nullptr;
    //this value we will ask the user later
}

Game::~Game(){
    cout << "Game over...\n";
    deleteLevel();
    if(player != nullptr){
        delete player;
    }
}

//will print and ask for menuoptions (DONE)
void Game::mainMenuOptions() {
    outputMenu.printMainMenu();

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
            deleteLevel();
            createDungeon(25);
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
    outputClassIntro.printClassIntro();
    
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
    cin.ignore(); cin.ignore();
}

//Function that starts a run by "traveling to dungeon..."
void Game::startDungeonRun() {
    cout << endl << "%%%%%% Traveling to dungeon... %%%%%%" << endl;
    cin.ignore();  
    
    currRoom->outputRoomDescription();

    bool isInDungeon = true;
    string input;
    while(isInDungeon) {
        currRoom->fightScreen();
        cout << "           Player health: " << player->getHealth() << endl;
        cin.ignore();

        if(currRoom->roomMonster->getHealth() > 0){
            cout << "Run or Fight (r, f) ";
        }else{
            changeRooms(0);
            continue;
        }
        cin >> input;
        cout << endl;
        //DO NOT FKN REMOVE THIS
        if(input == "quit" || input == "q"){
            break;
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
                    string itemIndex;
                    char temp = '!';
                    cout << "You collected an item! Choose the item number you want to use (Enter -1 if you want to save the item for now): " << endl;
                    cin >> itemIndex;
                    if(isdigit(itemIndex[0])){
                        temp = itemIndex[0];
                    }
                    int number = temp - '0';
                    if(number != -1){
                        player->useItemFromInventory(number);
                    }
                    roomNumber++;
                    if(currRoom->getRoomNumber() == 5){
                        onVictory();
                        break;
                    }
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
    if(totalSize < 9){
        throw("Dungeon size is less than 0");
    }
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
    currRoom = dungeonRooms.at(roomIndex - 1);
}

void Game::changeRooms(int num){
    if(currRoom->getItem() != nullptr && currRoom->visited() == false){
        player->addItemToInventory(currRoom->getItem());
    }
    currRoom->setVisited(true);
    vector<string> directions;
    int sqr = (int)(sqrt(totalDungeonSize));

    if(roomIndex > sqr) directions.push_back("North");
    if(roomIndex <= totalDungeonSize - sqr) directions.push_back("South");
    if(roomIndex % sqr != 1) directions.push_back("West");
    if(roomIndex % sqr != 0) directions.push_back("East");

    if(num == 1){
        changeRoom(directions.at(0));
        currRoom = dungeonRooms.at(roomIndex - 1);
        currRoom->outputRoomDescription();
    }else{
        bool wasDirection = false;
        while(!wasDirection){
            cout << "Which way would you like to go? You can go ";
            for(int i = 0; i < directions.size(); i++){
                cout << directions.at(i);
                if(i < directions.size() - 1){
                    cout << ", ";
                }
            }
            cout << endl;
            
            string input;
            cin >> input;
            for(int i = 0; i < directions.size(); i++){
                if(input == directions.at(i)){
                    wasDirection = true;
                    changeRoom(input);
                    currRoom = dungeonRooms.at(roomIndex - 1);
                    currRoom->outputRoomDescription();
                    break;
                }
            }
        }
    }
}

void Game::changeRoom(string& newRoom){
    if(newRoom == "East"){
        if(roomIndex + 1 >= dungeonRooms.size()){
            throw("Index out of bounds when trying to change rooms");
        }else{
            roomIndex++;
        }
    }       
    if(newRoom == "North"){
        if(roomIndex - (int)(sqrt(totalDungeonSize)) < 0){
            throw("Index out of bounds when trying to change rooms");
        }else{
            roomIndex -= (int)(sqrt(totalDungeonSize));
        }
    }
    if(newRoom == "South"){
        if(roomIndex + (int)(sqrt(totalDungeonSize)) >= dungeonRooms.size()){
            throw("Index out of bounds when trying to change rooms");
        }else{
            roomIndex += (int)(sqrt(totalDungeonSize));
        }
    }
    if(newRoom == "West"){
        if(roomIndex - 1 < 0){
            throw("Index out of bounds when trying to change rooms");
        }else{
            roomIndex--;
        }
    }
}

//ends the run if player dies (SEMI-DONE, needs better description)
void Game::onDeath() {
    cout << "You died" << endl;
    cout << "You beat " << roomNumber << " rooms." << endl;
    cout << "Your currency: " << player->getCurrency() << endl << endl;
    player->resetValues();
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
    outputShop.printShop();
    int input;

    while(true) {
        cin >> input;
        if(input == 1) {
            if(player->getCurrency() >= 5) {
                player->addCurrency(-5);
                player->setDamage(player->getDamage() + 1);
                cout << "   ## Damage buff purchased ##" << endl << endl;
                break;
            }
            else {
                cout << "       ## Not enough currency ##" << endl << endl;
                outputShop.printShop();
            }
        }
        if(input == 2) {
            if(player->getCurrency() >= 10) {
                player->addCurrency(-10);
                player->setHealth(player->getHealth() + 3);
                cout << "   Health buff purchased" << endl << endl;
                break;
            }
            else {
                cout << "       ## Not enough currency ##" << endl << endl;
                outputShop.printShop();
            }
        }
        if(input == 3) {break;}
    }
    mainMenuOptions();
}

void Game::deleteLevel(){
    for(int i = 0; i < dungeonRooms.size(); i++){
        delete dungeonRooms.at(i);
    }
    dungeonRooms.clear();
}

int Game::getRoomIndex(){
    return roomIndex;
}