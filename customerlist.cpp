#include "customerlist.h"

void CustomerList::push_back_customer(Customer data) {
    CustomerNode* newnode = new CustomerNode;
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

void CustomerList::temp_print() {
    CustomerNode* trav = this->first;
    while (trav != nullptr) {
        std::cout << trav->data.get_first_name() << " " << trav->data.get_credit_score()  
        << " " << trav->data.get_household_income() << " " <<trav->data.get_total_sales() << std::endl;
        trav = trav->next;
    }
    std::cout << std::endl;
}