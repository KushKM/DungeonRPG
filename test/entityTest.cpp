#include "gtest/gtest.h"
#include "entity.cpp"

TEST(entityTests, defaultConstructorHealth){
    Entity* testEntity = new Entity();
    EXPECT_DOUBLE_EQ(testEntity->getHealth(), 0.0);
}

TEST(entityTests, defaultConstructorDamage){
    Entity* testEntity = new Entity();
    EXPECT_DOUBLE_EQ(testEntity->getDamage(), 0.0);
}

TEST(entityTests, parameterizedConstructorHealth){
    Entity* testEntity = new Entity(10.0, 15.0);
    EXPECT_DOUBLE_EQ(testEntity->getHealth(), 10.0);
}

TEST(entityTests, parameterizedConstructorDamage){
    Entity* testEntity = new Entity(10.0, 15.0);
    EXPECT_DOUBLE_EQ(testEntity->getHealth(), 10.0);
}

TEST(entityTests, attackEnemy){
    Entity* attackingEntity = new Entity(10.0, 5.0);
    Entity* attackedEntity = new Entity(15.0, 8.0);
    attackingEntity->attackEnemy(attackedEntity);
    EXPECT_DOUBLE_EQ(attackedEntity->getHealth(), 10.0);
}

TEST(entityTests, takeDamage){
    Entity* testEntity = new Entity(10.0, 5.0);
    testEntity->takeDamage(3);
    EXPECT_DOUBLE_EQ(testEntity->getHealth(), 7.0);
}

TEST(entityTests, getCurrency){
    Entity* testEntity = new Entity();
    EXPECT_EQ(testEntity->getCurrency(), 0);
}