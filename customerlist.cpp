#include "customerlist.h"

/**
 * Pushes back customer object to customer list
*/
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


/**
 * Deletes list
*/
void CustomerList::delete_list() {
    CustomerNode* current = this->first;
    while (current != nullptr) {
        CustomerNode* del = current;
        current = current->next;
        delete del;
    }
    this->first = nullptr;
    this->last = nullptr;
}