//Created by Amal Afsal for Linked List lab on 10/13/23.

#ifndef QUEUECUSTOMER_H
#define QUEUECUSTOMER_H

#include <iostream>
#include <iomanip>
#include <fstream>

#include "customer.h"
#include "customernode.h"

//rank total sales and give highest bidder a high five

struct QueueCustomer {
    QueueCustomer();
    void push_back_in_order(Customer data);
    void push_back(Customer data);
    void pop_front();

    void print();

    void delete_queue();

    void offload_data(std::ofstream& off);

    CustomerNode* head;
    CustomerNode* tail;
};

#endif