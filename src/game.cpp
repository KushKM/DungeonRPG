#include "game.h"
#include <iostream>
#include <fstream>
using namespace std;

void printClasses();

Game::Game() {
}

void Game::createCharacter() {
    char choice = '-';
    printClassesIntro();
    cin >> choice;

    while(!(choice == 'a' || choice == 'b' || choice == 'c' || choice == 'd')) { 
        cout << "invalid choice. Try again: ";
        cin >> choice;
    }

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
    StartRun();
}

//Function that starts a run by "traveling to dungeon..."
void Game::StartRun() {
    cout << "Traveling to dungeon..." << endl;
    roomNumber++;
}

void Game::onDeath() {
}

void Game::endRun() {
}

void Game::displayShop() {
}

//Helper function to print out the class infos
void printClassesIntro() {
    ifstream file("helperFiles/classChoice.txt");
    if(file.is_open()) cout << file.rdbuf();
}

void Game::encounterMonster(){

}