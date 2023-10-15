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

void CountryList::temp_print() {
    CountryNode* trav = this->first;
    while (trav != nullptr) {
        std::cout << trav->data.get_name() << " " << trav->data.get_emissions()
        << " " << trav->data.get_population() << " " <<trav->data.get_area() << std::endl;
        trav = trav->next;
    }
    std::cout << std::endl;
}