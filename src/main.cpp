#include <iostream>

#include "monster.h"
#include "character.h"
#include "game.h"

using namespace std;

int main() {

    Game* g = new Game();
    g->createCharacter();
    g->createDungeon(25);
    g->startDungeonRun();
    delete g;

    return 0;
}