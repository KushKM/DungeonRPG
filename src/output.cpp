#include <iostream>
#include <fstream>
#include "output.h"

using namespace std;

MenuOutput::MenuOutput(){}

void MenuOutput::printMainMenu(){
    ifstream file("helperFiles/mainMenu.txt");
    if(file.is_open()) cout << file.rdbuf();
    file.close();
}

ClassIntroOutput::ClassIntroOutput(){}

void ClassIntroOutput::printClassIntro(){
    ifstream file("helperFiles/classChoice.txt");
    if(file.is_open()) cout << file.rdbuf();
    file.close();
}

ShopOutput::ShopOutput(){}

void ShopOutput::printShop(){
    ifstream file("helperFiles/shop.txt");
    if(file.is_open()) cout << file.rdbuf();
    file.close();
}