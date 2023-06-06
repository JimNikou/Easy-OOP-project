#include "item_class.hpp"
#include "customer_class.hpp"
#include "order_class.hpp"
#include <iostream>
#include <string>
#define N 100
using namespace std;


Order::Order(){
    return;
}

Order::Order(int orderNo1, string orderDate1, float totalAmount1, int custNo1, string custName1, string custEmail1, int itemNo1, string itemDesc1, float itemPrice1){
    orderNo = orderNo1;
    orderDate = orderDate1;
    totalAmount = totalAmount1;
    Customer::setData(custNo1, custName1, custEmail1);
    Item::setData(itemNo1, itemDesc1, itemPrice1);
}

void Order::readData(){
    Customer::readData();
    cout << "Dwse order number: ";
    cin >> orderNo;
    cout << "Dwse order date: ";
    cin >> orderDate;

}

void Order::setData(int orderNo1, string orderDate1, float totalAmount1, int custNo1, string custName1, string custEmail1, int itemNo1, string itemDesc1, float itemPrice1){
    orderNo = orderNo1;
    orderDate = orderDate1;
    totalAmount = totalAmount1;
    Customer::setData(custNo1, custName1, custEmail1);
    Item::setData(itemNo1, itemDesc1, itemPrice1);
}

void Order::printData(){
    cout << "Order Number: " << orderNo << endl;
    cout << "Order Date: " << orderDate << endl;
    cout << "Total Amount: " << totalAmount << endl;
    cout << endl;
}

int Order::getOrderNo(){
    return orderNo;
}

string Order::getOrderDate(){
    return orderDate;
}

float Order::getTotalAmount(){
    return totalAmount;
}

void Order::buyItem(float price, int qty){
    totalAmount += price * qty;
}

int Order::shippingCost(){
    if(totalAmount < 200)
        return 20;
    return 0;
}
