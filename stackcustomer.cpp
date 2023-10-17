#include "stackcustomer.h"

StackCustomer::StackCustomer() {
    this->head = nullptr;
}


void StackCustomer::push_in_order(Customer data) {
    CustomerNode* newnode = new CustomerNode;
    newnode->data = data;
    if (this->head == nullptr) {
        this->head = newnode;
    }
    else {
        CustomerNode* trav = head;
        while (trav->next != nullptr && trav->next->data.get_serialized_date() < newnode->data.get_serialized_date()) {
            trav = trav->next;
        }
        CustomerNode* temp = trav->next;
        trav->next = newnode;
        newnode->next = temp;
    }
}



void StackCustomer::push(Customer data) {
    CustomerNode* newnode = new CustomerNode;
    newnode->data = data;
    if (this->head == nullptr) {
        this->head = newnode;
    }
    else {
        newnode->next = head;
        head = newnode;
    }
}

void StackCustomer::pop() {
    if (head != nullptr) {
        CustomerNode* to_delete = head;
        head = head->next;
        delete to_delete;
    }
    else {
        std::cout << std::endl;
        std::cout << "Stack is empty." << std::endl;
    }
}