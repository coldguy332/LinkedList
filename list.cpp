#include "list.h"

List::List() {
    this->first = nullptr;
    this->last = nullptr;
}

void List::push_back_country(Country newcountry) {
    CountryNode* newnode = new CountryNode(newcountry);
    if (last == nullptr) {
        first = newnode;
        last = newnode;
    }
    else {
        last->next = newnode;
        last = newnode;
    }
}

void List::push_back_customer(Customer newcustomer) {
    CustomerNode* newnode = new CustomerNode(newcustomer);
    if (last == nullptr) {
        first = newnode;
        last = newnode;
    }
    else {
        last->next = newnode;
        last = newnode;
    }
}