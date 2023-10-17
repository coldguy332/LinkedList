//Created by Amal Afsal for Linked List lab on 10/11/23.

#ifndef CUSTOMERNODE_H
#define CUSTOMERNODE_H

#include "customer.h"

/**
 * Specifc node for customer objects
*/
struct CustomerNode {
    Customer data;
    CustomerNode* next = nullptr;
};

#endif