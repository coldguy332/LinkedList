#ifndef CUSTOMERNODE_H
#define CUSTOMERNODE_H

#include "customer.h"

struct CustomerNode {
    Customer data;
    CustomerNode* next = nullptr;
};

#endif