#include "item_class.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


Item::Item(){
    return;
}

Item::Item(int itemNo1, string itemDesc1, float itemPrice1){
    itemNo = itemNo1;
    itemDesc = itemDesc1;
    itemPrice = itemPrice1;
}

void Item::readData(){
    cout << "Dwse item Number: ";
    cin >> itemNo;
    cout << "Dwse item description: ";
    cin >> itemDesc;
    cout << "Dwse item price: ";
    cin >> itemPrice;
}

void Item::setData(int itemNo1, string itemDesc1, float itemPrice1){
    itemNo = itemNo1;
    itemDesc = itemDesc1;
    itemPrice = itemPrice1;
}

void Item::printData(){
    cout << "Item Code: " << itemNo << endl;
    cout << "Item Description: " << itemDesc << endl;
    cout << "Price: " << itemPrice << endl;
    cout << endl;
}

int Item::getItemNo(){
    return itemNo;
}

string Item::getItemDesc(){
    return itemDesc;
}

float Item::getItemPrice(){
    return itemPrice;
}

int fileToArr(ifstream &fin, Item p[]){
    int counter = 0;
    if(fin){
        string line;
        while (getline(fin, line) && counter < 100) {
            
            
            istringstream iss(line);
            
            int itemCode;
            std::string itemDescription;
            float price;
            
            
            if (iss >> itemCode >> ws && getline(iss, itemDescription, '\t') >> price) {
                p[counter++].setData(itemCode, itemDescription, price);
            }else{
                cout << "Lathos domh text file ITEMS" << endl;
            }
            
        }
    }else{
        cout << "File name is wrong." << endl;
    }
    
    return counter;
}


int itemMenu(Item p[], int n){
    int code;
    for(int i=0; i<n; ++i){
        p[i].printData();
    }
    cout << "Dwse item number gia to kalathi: ";
    cin >> code;
    
    return code;
}

int searchItem(Item p[], int n, int searchCode){
    for(int i=0; i<n; ++i){
        if(searchCode == p[i].getItemNo())
            return i;
    }
    return -1;
}
