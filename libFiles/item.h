#ifndef ITEM
#define ITEM 

using namespace std; 

class Item {
    private: 
    string name; 
    int healthPack; 
    int currency; 

    public: 
    Item();
    Item(string itemName, int health, int money);
    string getName() const;
    int getHealthPack() const; 
    int getCurrency() const; 
    void useHealthPack(); 
    void useCurrency();  

};

#endif