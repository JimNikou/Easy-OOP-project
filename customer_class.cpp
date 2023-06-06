#include "customer_class.hpp"
#include <iostream>
#include <string>
using namespace std;


Customer::Customer(){
    return;
}

Customer::Customer(int custNo1, string custName1, string custEmail1){
    custNo = custNo1;
    custName = custName1;
    custEmail = custEmail1;
}


void Customer::readData(){
    cout << "Dwse Customer Number: ";
    cin >> custNo;
    getchar();
    cout << "Dwse Customer Name: ";
    getline(cin, custName);
    cout << "Dwse Customer Email: ";
    cin >> custEmail;
}

void Customer::setData(int custNo1, string custName1, string custEmail1){
    custNo = custNo1;
    custName = custName1;
    custEmail = custEmail1;
}

void Customer::printData(){
    cout << "Customer Number: " << custNo << endl;
    cout << "Customer Name: " << custName << endl;
    cout << "Customer Email: " << custEmail << endl;
    cout << endl;
}

int Customer::getCustNo(){
    return custNo;
}

string Customer::getCustName(){
    return custName;
}

string Customer::getCustEmail(){
    return custEmail;
}
