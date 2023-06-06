#ifndef order_class_hpp
#define order_class_hpp
#include "item_class.hpp"
#include "customer_class.hpp"
#include <stdio.h>
#include <string>
using namespace std;

class Order : public Customer, public Item {
    private:
        int orderNo;
        string orderDate;
        float totalAmount;
    public:
        Order();
        Order(int orderNo1, string orderDate1, float totalAmount1, int custNo1, string custName1, string custEmail1, int itemNo1, string itemDesc1, float itemPrice1);
        void readData();
        void setData(int orderNo1, string orderDate1, float totalAmount1, int custNo1, string custName1, string custEmail1, int itemNo1, string itemDesc1, float itemPrice1);
        void printData();
        int getOrderNo();
        string getOrderDate();
        float getTotalAmount();
        void buyItem(float price, int qty);
        int shippingCost();
};

#endif /* order_class_hpp */
