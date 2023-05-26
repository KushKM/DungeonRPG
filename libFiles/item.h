#ifndef ITEM
#define ITEM 
#include <string>

using namespace std; 

class Item {
    private: 
        string name; 
        int healthPack; 
        int currencyPack; 
    public: 
        Item();
        Item(string itemName, int healthAmount, int currencyAmount);
        string getName(); 
        int getHealthPack();
        int getCurrency(); 
        virtual void use();  

};

class healthPack : public Item {
    private: 
    int healthAmount; 

    public:
        healthPack() : Item() {}
        healthPack(string itemName, int healthAmount) : Item(itemName, healthAmount, 0) {}
        void use() override; 
};

class currencyPack : public Item {
    private: 
    int currencyAmount; 

    public:
        currencyPack() : Item() {}
        currencyPack(string itemName, int currencyAmount) : Item(itemName, 0, currencyAmount) {}
        void use() override; 
};

#endif