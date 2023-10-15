#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include "customer.h"
#include "customernode.h"

struct CustomerList {

    void push_back_customer(Customer data);
    void temp_print();
    CustomerNode* first = nullptr;
    CustomerNode* last = nullptr;

};

#endif