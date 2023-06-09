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

TEST(clericTests, clericConstructor){
    Entity* clericTest = new Cleric();
    EXPECT_TRUE(clericTest->getHealth() == 30 && clericTest->getDamage() == 15);
}

TEST(clericTests, takeDamage){
    Entity* clericTest = new Cleric();
    clericTest->takeDamage(5);
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

TEST(wizardTests, wizardConstructor){
    Entity* wizardTest = new Wizard();
    EXPECT_TRUE(wizardTest->getHealth() == 20 && wizardTest->getDamage() == 20);
}

TEST(warriorTests, attackEnemy1){
    Entity* damagedEntity = new Entity(40.0, 10.0);
    Entity* testWarrior = new Warrior();
    testWarrior->takeDamage(10);
    testWarrior->attackEnemy(damagedEntity);
    EXPECT_EQ(damagedEntity->getHealth(), 15);
}

TEST(warriorTests, attackEnemy2){
    Entity* damagedEntity = new Entity(40.0, 10.0);
    Entity* testWarrior = new Warrior();
    testWarrior->takeDamage(20);
    testWarrior->attackEnemy(damagedEntity);
    EXPECT_EQ(damagedEntity->getHealth(), 10);
}

TEST(warriorTests, attackEnemy3){
    Entity* damagedEntity = new Entity(40.0, 10.0);
    Entity* testWarrior = new Warrior();
    testWarrior->takeDamage(30);
    testWarrior->attackEnemy(damagedEntity);
    EXPECT_EQ(damagedEntity->getHealth(), 5);
}

TEST(warriorTests, warriorConstructor){
    Entity* warriorTest = new Warrior();
    EXPECT_TRUE(warriorTest->getHealth() == 40 && warriorTest->getDamage() == 20);
}

TEST(rogueTests, rogueConstructor){
    Entity* rogueTest = new Rogue();
    EXPECT_TRUE(rogueTest->getHealth() == 17.5 && rogueTest->getDamage() == 25);
}

TEST(rogueTests, takeDamage){
    Entity* attackingEntity = new Entity(40.0, 10.0);
    Entity* testRogue = new Rogue();
    attackingEntity->attackEnemy(testRogue);
    EXPECT_TRUE(testRogue->getHealth() == 7.5 || testRogue->getHealth() == 17.5)
                << "Where health: " << testRogue->getHealth() << ", should equal 7.5 if you did not dodge or 17.5 if you did dodge.";
}
