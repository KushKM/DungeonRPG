#include <iostream>
#include <fstream>
#include "monster.h"
#include "character.h"

using namespace std;

int main() {

    string classChoice = "-1";

    ifstream file("helperFiles/classChoice.txt");
    if(file.is_open()) cout << file.rdbuf();
    cin >> classChoice;
    cout << "You chose " << classChoice << endl;
    return 0;

    // Character* c = new Character(10, 5, 100, 10);
    // Monster* m = new Monster(10, 5);
    // c->attackEnemy(m);
    
}