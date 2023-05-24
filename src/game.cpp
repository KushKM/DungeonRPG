#include "game.h"
#include <iostream>
#include <fstream>
using namespace std;

void printClassesIntro();

Game::Game() {}

//will print and ask for menuoptions (DONE)
void Game::mainMenuOptions() {
    cout << "Choose an option: " << endl;
    cout << "   1. Enter the dungeon" << endl;
    cout << "   2. Visit Shop." << endl;
    
    int choice = 0;
    cin >> choice;
    while(!(choice == 1 || choice == 2)) {
        cout << "Invalid Choice" << endl;
        cin >> choice;
    }

    switch(choice) {
        case 1:
            startDungeonRun();
        case 2:
            displayShop();
    }
}

//will present user to choose a class on game start (DONE)
void Game::createCharacter() {
    printClassesIntro();
    
    char choice = '-';
    cin >> choice;
    while(!(choice == 'a' || choice == 'b' || choice == 'c' || choice == 'd')) { 
        cout << "invalid choice. Try again: ";
        cin >> choice;
    }

    cout << "   ";
    switch(choice) {
        case 'a':
            cout << "You chose the wizard." << endl;
            this->player = new Character(20, 15, 10, 5);
            break;
        case 'b':
            cout << "You chose the rogue." << endl;
            this->player = new Character(30, 20, 10, 8);
            break;
        case 'c':
            cout << "You chose the brute." << endl;
            this->player = new Character(40, 15, 10, 1);
            break;
        case 'd':
            cout << "You chose the cleric." << endl;
            this->player = new Character(30, 20, 10, 3);
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
}

//ends the run if player dies (SEMI-DONE, needs better description)
void Game::onDeath() {
    cout << "You died" << endl;
    cout << "You beat " << roomNumber << " rooms." << endl;
    cout << "Your currency: " << player->getCurrency() << endl;
    mainMenuOptions();
}

//ends the run if player wins (SEMI-DONE, needs better description)
void Game::onVictory() {
    cout << "You won" << endl;
    cout << "You beat " << roomNumber << " rooms." << endl;
    cout << "Your currency: " << player->getCurrency() << endl;
    mainMenuOptions();

}

void Game::displayShop() {
}

//Helper function to print out the class infos (DONE)
void printClassesIntro() {
    ifstream file("helperFiles/classChoice.txt");
    if(file.is_open()) cout << file.rdbuf();
}

void Game::encounterMonster(){

}