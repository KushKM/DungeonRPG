#include "gtest/gtest.h"
#include "entity.cpp"
#include "cleric.cpp"
#include "rogue.cpp"
#include "warrior.cpp"
#include "wizard.cpp"
#include "monster.cpp"
#include "character.cpp"
#include "item.cpp"

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

TEST(clericTests, takeDamage){
    Entity* clericTest = new Cleric();
    clericTest->takeDamage(5);
    cout <<  clericTest->getHealth() << endl;
    EXPECT_TRUE(clericTest->getHealth() == 25 || clericTest->getHealth() == 28)
                << "Where health: " << clericTest->getHealth() << ", should equal 25 if you don't heal or 28 if you do heal.";

}

TEST(wizardTests, attackEnemy){
    Entity* damagedEntity = new Entity(40.0, 10.0);
    Entity* testWizard = new Wizard();
    testWizard->attackEnemy(damagedEntity);
    cout << damagedEntity->getHealth() << endl;
    EXPECT_TRUE(damagedEntity->getHealth() == 20 || damagedEntity->getHealth() == 5)
                << "Where health: " << damagedEntity->getHealth() << ", should equal 5 if you get a crit or 20 if you don't.";

}

TEST(warriorTests, attackEnemy){
    Entity* damagedEntity = new Entity(40.0, 10.0);
    Entity* testWarrior = new Warrior();
    testWarrior->takeDamage(20);
    cout << testWarrior->getDamage() << endl;
    testWarrior->attackEnemy(damagedEntity);
    EXPECT_EQ(damagedEntity->getHealth(), 15);
}