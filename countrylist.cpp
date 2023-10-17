#include "countrylist.h"

/**
 * Pushes back country objects in a list made for country objects;
*/
void CountryList::push_back_country(Country data) {
    CountryNode* newnode = new CountryNode;
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
 * Deletes nodes within country list to hopefully avoid memory leaks
*/
void CountryList::delete_list() {
    CountryNode* current = this->first;
    while (current != nullptr) {
        CountryNode* del = current;
        current = current->next;
        delete del;
    }
    this->first = nullptr;
    this->last = nullptr;
}