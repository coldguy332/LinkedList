#include "queuecountry.h"

QueueCountry::QueueCountry() {
    this->head = nullptr;
    this->tail = nullptr;
}

void QueueCountry::push_back_in_order(Country data) {
    CountryNode* newnode = new CountryNode;
    newnode->data = data;
    if (this->head == nullptr) {
        this->head = newnode;
        this->tail = newnode;
    }
    else {
        if (newnode->data.get_year() < head->data.get_year()) {
            newnode->next = head;
            head = newnode;
        }
        else {
            CountryNode* trav = head;
            while (trav->next != nullptr && trav->next->data.get_year() < newnode->data.get_year()) {
                trav = trav->next;
            }
            if (trav == tail) {
                tail->next = newnode;
                tail = newnode;
            }
            else {
                CountryNode* temp = trav->next;
                trav->next = newnode;
                newnode->next = temp;
            }
        }
    }
}

void QueueCountry::push_back(Country data) {
    CountryNode* newnode = new CountryNode;
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

void QueueCountry::pop_front() {
    if (head != nullptr) {
        CountryNode* to_delete = head;
        head = head->next;
        delete to_delete;
    }
    else {
        std::cout << std::endl;
        std::cout << "Queue is empty." << std::endl;
    }
}

void QueueCountry::print() {
    std::cout << std::endl;
    std::cout << "Current head: " << this->head->data.get_name() << std::setw(20) << std::right<< this->head->data.get_year(); 
    std::cout << std::setw(20) << std::right << this->head->data.get_emissions() << std::endl;
    std::cout << "        Tail: " << this->tail->data.get_name() << std::setw(20) << std::right << this->tail->data.get_year(); 
    std::cout << std::setw(20) << std::right << this->tail->data.get_emissions() << std::endl;
    std::cout << std::endl;
}

void QueueCountry::delete_queue() {
    CountryNode* current = this->head;
    while (current != nullptr) {
        CountryNode* del = current;
        current = current->next;
        delete del;
    }
    this->head = nullptr;
    this->tail = nullptr;
}