#include "game.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

void printClassesIntro();
void printMainMenu();

Game::Game(){
    srand(time(NULL));
}

Game::~Game(){
    cout << "Game over...\n";
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
    
    roomNumber = 1;
    currRoom = new Room(roomNumber);
    
    currRoom->outputRoomDescription();

    bool isInDungeon = true;
    string input;
    Monster* monster = currRoom->roomMonster;
    while(isInDungeon) {
        currRoom->fightScreen();
        cout << "Player health: " << player->getHealth() << endl << endl;
        cin.ignore();
        cout << "Run or Fight? (r/f): ";
        cin >> input;
        cout << endl;
        if(input == "quit"){
            break;
        }
        if(input == "r" || input == "run") {
            player->attemptRun();
            if(player->getHealth() <= 0){
                onDeath();
                break;
            }
        }
        if(input == "f" || input == "fight") {
            if(monster != nullptr){
                player->attackEnemy(monster);
                if(monster->getHealth() <= 0){
                    monster->monsterItemDrop(player); 
                    player->listInventory();
                    delete monster; 
                    monster = nullptr; 
                    break;
                }
                else{
                    monster->attackEnemy(player);
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
    cout << "hello this is the shop" << endl;
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