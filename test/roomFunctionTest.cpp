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

TEST(roomOutOfBoundsTest, boundsTest1){
    Game* game = new Game();
    game->createDungeon(49);
    string input = "South";
    game->changeRoom(input);
    game->changeRoom(input);
    game->changeRoom(input);
    EXPECT_ANY_THROW(game->changeRoom(input));
    delete game;
}

TEST(roomOutOfBoundsTest, boundsTest2){
    Game* game = new Game();
    game->createDungeon(49);
    string input = "North";
    game->changeRoom(input);
    game->changeRoom(input);
    game->changeRoom(input);
    EXPECT_ANY_THROW(game->changeRoom(input));
    delete game;
}

TEST(roomOutOfBoundsTest, boundsTest3){
    Game* game = new Game();
    game->createDungeon(49);
    string input = "West";
    for(int i = 0; i < 22; i++){
        game->changeRoom(input);
    }
    EXPECT_ANY_THROW(game->changeRoom(input));
    delete game;
}

TEST(roomOutOfBoundsTest, boundsTest4){
    Game* game = new Game();
    game->createDungeon(49);
    string input = "East";
    for(int i = 0; i < 26; i++){
        game->changeRoom(input);
    }
    EXPECT_ANY_THROW(game->changeRoom(input));
    delete game;
}

TEST(roomOutOfBoundsTest, boundsTest5){
    Game* game = new Game();
    game->createDungeon(49);
    string input = "North";
    game->changeRoom(input);
    EXPECT_NO_THROW(game->changeRoom(input));
    delete game;
}

TEST(roomOutOfBoundsTest, boundsTest6){
    Game* game = new Game();
    game->createDungeon(49);
    string input = "South";
    game->changeRoom(input);
    EXPECT_NO_THROW(game->changeRoom(input));
    delete game;
}

TEST(roomOutOfBoundsTest, boundsTest7){
    Game* game = new Game();
    game->createDungeon(49);
    string input = "West";
    game->changeRoom(input);
    EXPECT_NO_THROW(game->changeRoom(input));
    delete game;
}

TEST(roomOutOfBoundsTest, boundsTest8){
    Game* game = new Game();
    game->createDungeon(49);
    string input = "East";
    game->changeRoom(input);
    EXPECT_NO_THROW(game->changeRoom(input));
    delete game;
}

TEST(roomOutOfBoundsTest, boundsTest9){
    Game* game = new Game();
    game->createDungeon(49);
    string input = "North";
    game->changeRoom(input);
    input = "South";
    game->changeRoom(input);
    input = "East";
    game->changeRoom(input);
    game->changeRoom(input);
    EXPECT_NO_THROW(game->changeRoom(input));
    delete game;
}

TEST(roomOutOfBoundsTest, validRoomSize){
    Game* game = new Game();
    EXPECT_ANY_THROW(game->createDungeon(-14));
    delete game;
}

TEST(roomOutOfBoundsTest, validRoomSize2){
    Game* game = new Game();
    EXPECT_ANY_THROW(game->createDungeon(0));
    delete game;
}

TEST(roomOutOfBoundsTest, validRoomSize3){
    Game* game = new Game();
    EXPECT_NO_THROW(game->createDungeon(12));
    delete game;
}

TEST(roomOutOfBoundsTest, validRoomSize4){
    Game* game = new Game();
    EXPECT_ANY_THROW(game->createDungeon(8));
    delete game;
}

TEST(roomOutOfBoundsTest, validRoomSize5){
    Game* game = new Game();
    EXPECT_NO_THROW(game->createDungeon(108.478));
    delete game;
}

