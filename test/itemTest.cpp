#include "gtest/gtest.h"
#include "item.cpp"


TEST(ItemTests, getName) {
    Item* item = new Item("Item");
    EXPECT_EQ(item->getName(), "Item");
    delete item;
}

TEST(HealthPackTests, getHealthAmount) {
    HealthPack* healthPack = new HealthPack("Health Pack", 50);
    EXPECT_EQ(healthPack->getHealthAmount(), 50);
    delete healthPack;
}

TEST(CurrencyPackTests, getCurrencyAmount) {
    CurrencyPack* currencyPack = new CurrencyPack("Currency Pack", 100);
    EXPECT_EQ(currencyPack->getCurrencyAmount(), 100);
    delete currencyPack;
}

TEST(DamageBoosterTests, getName) {
    DamageBooster* damageBooster = new DamageBooster("Damage Booster");
    EXPECT_EQ(damageBooster->getName(), "Damage Booster");
    delete damageBooster;
}