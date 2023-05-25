#include <iostream>

#include "monster.h"
#include "character.h"
#include "game.h"

using namespace std;

int main() {

    Game* g = new Game();
    g->createCharacter();
    g->startDungeonRun();

    // Character* c = new Character(10, 5, 100, 10);
    // Monster* m = new Monster(10, 5);
    // c->attackEnemy(m);
    
}