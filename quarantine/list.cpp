#include "list.h"

List::List() {
    this->first_one = nullptr;
    this->last_one = nullptr;
    this->first_two = nullptr;
    this->last_two = nullptr;
}

void List::push_back_country(Country newcountry) {
    CountryNode* countrynode = new CountryNode(newcountry);
    if (last_two == nullptr) {
        first_two = newnode;
        last_two = newnode;
    }
    else {
        last_two->next = newnode;
        last_two = newnode;
    }
}

void List::push_back_customer(Customer newcustomer) {
    CustomerNode* customernode = new CustomerNode(newcustomer);
    if (last_one == nullptr) {
        first_one = newnode;
        last_one = newnode;
    }
    else {
        last_one->next = newnode;
        last_one = newnode;
    }
} 