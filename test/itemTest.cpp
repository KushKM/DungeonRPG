#include "gtest/gtest.h"
#include "item.h"


TEST(ItemTests, getName) {
    Item* item = new Item("Item");
    EXPECT_EQ(item->getName(), "Item");
    delete item;
}

TEST(HealthPackTests, getHealthAmount) {
    healthPack* hp = new healthPack("Health Pack", 50);
    EXPECT_EQ(hp->getHealthAmount(), 50);
    delete hp;
}

TEST(CurrencyPackTests, getCurrencyAmount) {
    currencyPack* cp = new currencyPack("Currency Pack", 100);
    EXPECT_EQ(cp->getCurrencyAmount(), 100);
    delete cp;
}

TEST(DamageBoosterTests, getName) {
    damageBooster* db = new damageBooster("Damage Booster");
    EXPECT_EQ(db->getName(), "Damage Booster");
    delete db;
}

