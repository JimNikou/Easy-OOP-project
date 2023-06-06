#include "item_class.hpp"
#include "customer_class.hpp"
#include "order_class.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cerrno>
#include <iomanip>
using namespace std;
#define N 100

int main(int argc, const char * argv[]) {
    Item itemArr[N];
    int itemArrNumberOfProducts[N];
    
    for(int i=0; i<N; ++i){
        itemArrNumberOfProducts[i] = 0;
    }
    
    
    string location = "/applications/oop_proj/oop_proj_this/oop_proj_final/oop_proj_final/";
    ifstream infile(location+"ITEMS.txt");
    
    
    //1
    int rtnd_items = fileToArr(infile, itemArr); //adding the items to the class array
    
    //2
    Order custOrd;
    custOrd.readData();
    
    //3 - 4
    int given_code = itemMenu(itemArr,rtnd_items);
    
    //5
    int counter = 0;
    while(given_code!=0){
        int code_check = searchItem(itemArr, rtnd_items, given_code);
        if(code_check != -1){
            cout << "Selected item exists! Give the amount of items you want to purchase: ";
            int number_to_purchase;
            cin >> number_to_purchase;
            itemArrNumberOfProducts[code_check] += number_to_purchase;
            custOrd.buyItem(itemArr[code_check].getItemPrice(), number_to_purchase);
        }else{
            cout << "Item does not exist." << endl;
        }
        counter++;
        given_code = itemMenu(itemArr, rtnd_items);
    }
        
        
    
    
    
    
    
    
    
    std::ofstream outfile(location + "ORDERS21002.txt");

    if (outfile.is_open()) {
        // Write customer information
        outfile << setw(16) << left << "Customer No:" << custOrd.getCustNo() << endl;
        outfile << setw(16) << left << "Customer Name:" << custOrd.getCustName() << endl;
        outfile << setw(16) << left << "Customer Email:" << custOrd.getCustEmail() << endl;
        outfile << setw(16) << left << "Order No:" << custOrd.getOrderNo() << endl;
        outfile << setw(16) << left << "Order Date:" << custOrd.getOrderDate() << endl;
        outfile << endl;

        // Write table header
        outfile << setw(8) << left << "Kwdikos" << setw(20) << left << "Perigrafh" << setw(10) << left << "Posotita" << setw(8) << left << " Timi" << setw(8) << left << " Axia" << endl;
        outfile << setw(8) << left << "=======" << setw(20) << left << "==================" << setw(10) << left << "========" << setw(8) << left << "======" << setw(8) << left << "======" << endl;

        for (int i = 0; i < N; ++i) {
            if (itemArrNumberOfProducts[i] != 0) {
                // Write each row of the table with aligned columns
                outfile << setw(8) << left << itemArr[i].getItemNo() << setw(20) << left << itemArr[i].getItemDesc() << setw(10) << left << itemArrNumberOfProducts[i] << setw(8) << left << itemArr[i].getItemPrice() << setw(8) << left << itemArrNumberOfProducts[i] * itemArr[i].getItemPrice() << endl;
            }
        }

        int shipping_cost = custOrd.shippingCost();
        outfile << endl;
        outfile << setw(16) << left << "Total worth:" << custOrd.getTotalAmount() + shipping_cost << endl;
        outfile << setw(16) << left << "Shipping:" << shipping_cost << endl;

        outfile.close();
    } else {
        cout << "ORDERS.TXT not opened correctly." << endl;
    }
    
    return 0;
}


