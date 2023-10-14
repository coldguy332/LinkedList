#include "countrylist.h"

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