#include "stackcountry.h"

StackCountry::StackCountry() {
    this->head = nullptr;
}

void StackCountry::push_in_order(Country data) {
    CountryNode* newnode= new CountryNode;
    newnode->data = data;
    if(this->head == nullptr) {
        this->head = newnode;
    }
    else {
        CountryNode* trav = head;
        while (trav->next != nullptr && trav->next->data.get_year() < newnode->data.get_year()) {
            trav = trav->next;
        }
        CountryNode* temp = trav->next;
        trav->next = newnode;
        newnode->next = temp;
    }
}

void StackCountry::push(Country data) {
    CountryNode* newnode = new CountryNode;
    newnode->data = data;
    if (this->head == nullptr) {
        this->head = newnode;
    }
    else {
        newnode->next = head;
        head = newnode;
    }
}

void StackCountry::pop() {
    if (head != nullptr) {
        CountryNode* to_delete = head;
        head = head->next;
        delete to_delete;
    }
    else {
        std::cout << std::endl;
        std::cout << "Stack is empty." << std::endl;
    }
}

void StackCountry::print() {
    CountryNode* trav = this->head;
    while (trav->next != nullptr) {
        trav = trav->next;
    }
    std::cout << std::endl;
    std::cout << "Current head: " << this->head->data.get_name() << std::setw(10) << std::left << this->head->data.get_year() 
              << std::setw(10) << std::left << this->head->data.get_emissions() << std::endl;
    std::cout << "Tail: " << trav->data.get_name() << std::setw(10) << std::left << trav->data.get_year() 
              << std::setw(10) << std::left << trav->data.get_emissions() << std::endl;
    std::cout << std::endl;
}