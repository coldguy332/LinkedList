//Created by Amal Afsal for Linked List lab on 10/13/23.
#ifndef STACKCUSTOMER_H
#define STACKCUSTOMER_H

#include <iostream>
#include <iomanip>
#include <fstream>

#include "customer.h"
#include "customernode.h"

//Will Hold most loyal customers
struct StackCustomer {
    
    StackCustomer();

    void push_in_order(Customer data);

    void push(Customer data);
    void pop();
    void print();

    void delete_stack();

    void offload_data(std::ofstream& off);

    CustomerNode* head;
};

#endif 