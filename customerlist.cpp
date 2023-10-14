#include "customerlist.h"

void CustomerList::push_back_customer(Customer data) {
    CustomerNode* newnode = new CustomerNode;
    newnode->data = data;
    if (this->last == nullptr) {
        this->first = newnode;
        this->last = newnode;
    }
    else {
        this->last->next = newnode;
        this->last = newnode;
    }
}