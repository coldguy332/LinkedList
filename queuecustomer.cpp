#include "queuecustomer.h"

QueueCustomer::QueueCustomer() {
    this->head = nullptr;
    this->tail = nullptr;
}

void QueueCustomer::push_back_in_order(Customer data) {
    CustomerNode* newnode = new CustomerNode;
    if (this->head == nullptr) {
        this->head = newnode;
        this->tail = newnode;
    }
    else {
        CustomerNode* trav = head;
        while (trav->next != nullptr && trav->next->data.get_total_sales() > newnode->data.get_total_sales()) {
            trav = trav->next;
        }
        CustomerNode* temp = trav->next;
        trav->next = newnode;
        newnode->next = temp;
    }
}

void QueueCustomer::push_back(Customer data) {
    CustomerNode* newnode = new CustomerNode;
    newnode->data = data;
    if (tail == nullptr) {
        head = newnode;
        tail = newnode;
    }
    else {
        tail->next = newnode;
        tail = newnode;
    }
}

void QueueCustomer::pop_front() {
    if (head != nullptr) {
        CustomerNode* to_delete = head;
        head = head->next;
        delete to_delete;
    }
    else {
        std::cout << std::endl;
        std::cout << "Queue is empty." << std::endl;
    }
}

void QueueCustomer::print() {
    std::cout << std::endl;
    std::cout << "Current head: " << this->head->data.get_first_name() + " " + this->head->data.get_last_name() << std::setw(10) << std::left 
              << this->head->data.get_total_sales() << std::endl;
    std::cout << "Tail: " << this->tail->data.get_first_name() + " " + this->tail->data.get_last_name() << std::setw(10) << std::left 
              << this->tail->data.get_serialized_date() << std::endl;
    std::cout << std::endl;
}