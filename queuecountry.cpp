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
        CountryNode* trav = head;
        while (trav->next != nullptr && trav->next->data.get_emissions() < newnode->data.get_emissions()
               && trav->next->data.get_year() <= newnode->data.get_year()) {
            trav = trav->next;
        }
        CountryNode* temp = trav->next;
        trav->next = newnode;
        newnode->next = temp;
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