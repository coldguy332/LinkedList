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
        if (newnode->data.get_serialized_date() > head->data.get_serialized_date()) {
            newnode->next = head;
            head = newnode;;
        }
        else {
            CustomerNode* trav = head;
            while (trav->next != nullptr && trav->next->data.get_serialized_date() > newnode->data.get_serialized_date()) {
                trav = trav->next;
            }
            CustomerNode* temp = trav->next;
            trav->next = newnode;
            newnode->next = temp;
        } 
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

void StackCustomer::print() {
    CustomerNode* trav = this->head;
    while (trav->next != nullptr) {
        trav = trav->next;
    }
    std::cout << std::endl;
    std::cout << "Current head: " << this->head->data.get_first_name() + " " + this->head->data.get_last_name() << std::setw(30) << std::right 
              << this->head->data.get_customer_since() << std::endl;
    std::cout << "        Tail: " << trav->data.get_first_name() + " " + trav->data.get_last_name() << std::setw(30) << std::right 
              << trav->data.get_customer_since() << std::endl;
    std::cout << std::endl;
}

void StackCustomer::delete_stack() {
    CustomerNode* current = this->head;
    while (current != nullptr) {
        CustomerNode* del = current;
        current = current->next;
        delete del;
    }
    this->head = nullptr;
}