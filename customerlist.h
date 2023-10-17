//Created by Amal Afsal for Linked List lab on 10/11/23.

#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include "customer.h"
#include "customernode.h"

struct CustomerList {

    void push_back_customer(Customer data);
    void delete_list();
    CustomerNode* first = nullptr;
    CustomerNode* last = nullptr;

};

#endif