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