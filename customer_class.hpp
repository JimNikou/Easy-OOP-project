#ifndef customer_class_hpp
#define customer_class_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Customer {
    private:
        int custNo;
        string custName;
        string custEmail;
    public:
        Customer();
        Customer(int custNo1, string custName1, string custEmail1);
        void readData();
        void setData(int custNo1, string custName1, string custEmail1);
        void printData();
        int getCustNo();
        string getCustName();
        string getCustEmail();
};

#endif /* customer_class_hpp */
