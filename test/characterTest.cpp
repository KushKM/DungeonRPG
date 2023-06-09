#include "gtest/gtest.h"
#include "entity.cpp"
#include "monster.cpp"
#include "character.cpp"
#include "item.cpp"

TEST(CharacterTests, defaultConstructor){
    Character character;
    EXPECT_DOUBLE_EQ(character.getHealth(), 0.0);
    EXPECT_DOUBLE_EQ(character.getDamage(), 0.0);
    EXPECT_EQ(character.getCurrency(), 0);
    EXPECT_EQ(character.getSpeed(), 0);
}

TEST(CharacterTests, constructor) {
    Character character(25.0, 20.0, 50, 10);
    EXPECT_DOUBLE_EQ(character.getHealth(), 25.0);
    EXPECT_DOUBLE_EQ(character.getDamage(), 20.0);
    EXPECT_EQ(character.getCurrency(), 50);
    EXPECT_EQ(character.getSpeed(), 10);
}


TEST(CharacterTests, useItemFromInventory) {
    Character character;
    Item* item1 = new Item("Item");
    character.addItemToInventory(item1);
    character.useItemFromInventory(0);
    EXPECT_EQ(character.getInventorySize(), 0);
    delete item1;
}