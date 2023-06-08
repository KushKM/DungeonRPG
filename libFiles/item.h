#ifndef ITEM
#define ITEM
#include <string>

using namespace std; 

class Character;


class Item {
    private: 
        string name; 
        int healthPack; 
        int currencyPack; 
        Character* player; 
    public: 
        Item();
        Item(string itemName, int healthAmount, int currencyAmount);
        string getName(); 
        int getHealthPack();
        int getCurrency(); 
        virtual void use(Character* player);

};

class healthPack : public Item {
    private: 
    int healthAmount; 

    public:
        healthPack() : Item() {}
        healthPack(string itemName, int healthAmount) : Item(itemName, healthAmount, 0) {}
        void use(Character* player) override; 
};

class currencyPack : public Item {
    private: 
    int currencyAmount; 

    public:
        currencyPack() : Item() {}
        currencyPack(string itemName, int currencyAmount) : Item(itemName, 0, currencyAmount) {}
        void use(Character* player) override; 
};


class damageBooster : public Item { 
    public: 
    damageBooster() : Item() {}
    damageBooster(string itemName) : Item(itemName, 0, 0) {}
    void use(Character* player) override; 
};

class Shield : public Item {
    public:
    Shield() : Item() {}
    Shield(string itemName) : Item(itemName, 0, 0) {}
    void use(Character* player) override;

};

#endif