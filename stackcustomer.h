#ifndef STACKCUSTOMER_H
#define STACKCUSTOMER_H

#include <iostream>

#include "customer.h"
#include "customernode.h"

//Will Hold most loyal customers
struct StackCustomer {
    
    StackCustomer();

    void push_in_order(Customer data);

    void push(Customer data);
    void pop();
    CustomerNode* head;
};

#endif 