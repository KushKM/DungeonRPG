#include "gtest/gtest.h"
#include "../libFiles/game.h"
using namespace std;

TEST(roomSwitchingTest, startRoomIndexPASS1){
    Game* game = new Game();
    game->createDungeon(49);
    EXPECT_EQ(22, game->getRoomIndex());
    delete game;
}

TEST(roomSwitchingTest, startRoomIndexPASS2){
    Game* game = new Game();
    game->createDungeon(25);
    EXPECT_EQ(11, game->getRoomIndex());
    delete game;
}

TEST(roomSwitchingTest, startRoomIndexPASS3){
    Game* game = new Game();
    game->createDungeon(9);
    EXPECT_EQ(4, game->getRoomIndex());
    delete game;
}

TEST(roomSwitchingTest, startRoomIndexFAIL1){
    Game* game = new Game();
    game->createDungeon(49);
    EXPECT_FALSE(19 == game->getRoomIndex());
    delete game;
}

TEST(roomSwitchingTest, changingIndex){
    Game* game = new Game();
    game->createDungeon(49);
    string input = "North";
    game->changeRoom(input);
    EXPECT_EQ(15, game->getRoomIndex());
    delete game;
}

TEST(roomSwitchingTest, changingIndex2){
    Game* game = new Game();
    game->createDungeon(49);
    string input = "South";
    game->changeRoom(input);
    EXPECT_EQ(29, game->getRoomIndex());
    delete game;
}

TEST(roomSwitchingTest, changingIndex3){
    Game* game = new Game();
    game->createDungeon(49);
    string input = "East";
    game->changeRoom(input);
    EXPECT_EQ(23, game->getRoomIndex());
    delete game;
}

TEST(roomSwitchingTest, changingIndex4){
    Game* game = new Game();
    game->createDungeon(49);
    string input = "West";
    game->changeRoom(input);
    EXPECT_EQ(21, game->getRoomIndex());
    delete game;
}

TEST(roomSwitchingTest, changingIndex5){
    Game* game = new Game();
    game->createDungeon(49);
    string input = "North";
    game->changeRoom(input);
    input = "South";
    game->changeRoom(input);
    EXPECT_EQ(22, game->getRoomIndex());
    delete game;
}
