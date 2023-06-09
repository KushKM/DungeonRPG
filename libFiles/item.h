#ifndef ITEM
#define ITEM
#include <string>

using namespace std; 



class Item {
    private: 
        string name; 
    public: 
        Item();
        Item(string itemName);
        virtual ~Item() {}
        string getName(); 

};

class healthPack : public Item {
    private: 
    int healthAmount; 

    public:
        healthPack() : Item() {}
        healthPack(string itemName, int healthAmount) : Item(itemName), healthAmount(healthAmount) {}
        int getHealthAmount() {return healthAmount; }
};

class currencyPack : public Item {
    private: 
    int currencyAmount; 

    public:
        currencyPack() : Item() {}
        currencyPack(string itemName, int currencyAmount) : Item(itemName), currencyAmount(currencyAmount) {}
};


class damageBooster : public Item { 
    public: 
    damageBooster() : Item() {}
    damageBooster(string itemName) : Item(itemName) {}
};

// class Shield : public Item {
//     public:
//     Shield() : Item() {}
//     Shield(string itemName) : Item(itemName) {}
// };

#endif