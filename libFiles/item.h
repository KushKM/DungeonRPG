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
        void useHealthPack(); 
        void useCurrency();  
};

#endif