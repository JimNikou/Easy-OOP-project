#ifndef item_class_hpp
#define item_class_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Item {
    private:
        int itemNo;
        string itemDesc;
        float itemPrice;
    public:
        Item();
        Item(int itemNo1, string itemDesc1, float itemPrice1);
        void readData();
        void setData(int itemNo1, string itemDesc1, float itemPrice1);
        void printData();
        int getItemNo();
        string getItemDesc();
        float getItemPrice();
        
        
};

int fileToArr(ifstream &fin, Item p[]);
int itemMenu(Item p[], int n);
int searchItem(Item p[], int n, int searchCode);
    
#endif /* item_class_hpp */
