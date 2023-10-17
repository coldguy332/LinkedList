#include "queuecustomer.h"

QueueCustomer::QueueCustomer() {
    this->head = nullptr;
    this->tail = nullptr;
}

void QueueCustomer::push_back_in_order(Customer data) {
    CustomerNode* newnode = new CustomerNode;
    newnode->data = data;
    if (this->head == nullptr) {
        this->head = newnode;
        this->tail = newnode;
    }
    else {
        if (newnode->data.get_total_sales() > head->data.get_total_sales()) {
            newnode->next = head;
            head = newnode;
        }
        else {
            CustomerNode* trav = head;
            while (trav->next != nullptr && trav->next->data.get_total_sales() > newnode->data.get_total_sales()) {
                trav = trav->next;
            }
            if (trav == tail) {
                tail->next = newnode;
                tail = newnode;
            }
            else {
                CustomerNode* temp = trav->next;
                trav->next = newnode;
                newnode->next = temp;
            }
        }
    }
}

void QueueCustomer::push_back(Customer data) {
    CustomerNode* newnode = new CustomerNode;
    newnode->data = data;
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
    std::cout << "Current head: " << this->head->data.get_first_name() + " " + this->head->data.get_last_name() << std::setw(10) << std::right 
              << this->head->data.get_total_sales() << std::endl;
    std::cout << "        Tail: " << this->tail->data.get_first_name() + " " + this->tail->data.get_last_name() << std::setw(10) << std::right
              << this->tail->data.get_total_sales() << std::endl;
    std::cout << std::endl;
}

void QueueCustomer::delete_queue() {
    CustomerNode* current = this->head;
    while (current != nullptr) {
        CustomerNode* del = current;
        current = current->next;
        delete del;
    }
    this->head = nullptr;
    this->tail = nullptr;
}

void QueueCustomer::offload_data(std::ofstream& off) {
    off.open("save.csv");
    off << "First Name" << "," << "Last Name" << "," << "Total Sales" << std::endl;
    CustomerNode* trav = this->head;
    while (trav != nullptr) {
        off << trav->data.get_first_name() << "," << trav->data.get_last_name() << "," << trav->data.get_total_sales();
        if (trav->next != nullptr) {
            std::cout << std::endl;
        }
        trav = trav->next;
    }
}