#include "stackcountry.h"

/**
 * Stack default constructor
*/
StackCountry::StackCountry() {
    this->head = nullptr;
}

/**
 * Pusshes objects in order
 * ONLY DO THIS ONCE
*/
void StackCountry::push_in_order(Country data) {
    CountryNode* newnode= new CountryNode; //creates a new node
    newnode->data = data; //new node takes in data
    if(this->head == nullptr) { //if head is null, new node becomes head
        this->head = newnode;
    }
    else {
        if (newnode->data.get_year() > head->data.get_year()) { //if newnode is greater than head, newnode becomes new head
            newnode->next = head;
            head = newnode;
        }
        else {
            CountryNode* trav = head; //ptr to head traverses until it's value is greater than newnode
            while (trav->next != nullptr && trav->next->data.get_year() > newnode->data.get_year()) {
                trav = trav->next;
            }
            CountryNode* temp = trav->next;
            trav->next = newnode; //trav points to newnode
            newnode->next = temp; //newnode points to trav->next
        }
    }
}

/**
 * Pushing one object to stack
*/
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

/**
 * Removes one object from stack
*/
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

/**
 * Prints stack node information
*/
void StackCountry::print() {
    CountryNode* trav = this->head;
    while (trav->next != nullptr) {
        trav = trav->next;
    }
    std::cout << std::endl;
    std::cout << "Current head: " << this->head->data.get_name() << std::setw(30) << std::right << this->head->data.get_year() 
              << std::setw(30) << std::right << this->head->data.get_emissions() << std::endl;
    std::cout << "        Tail: " << trav->data.get_name() << std::setw(30) << std::right << trav->data.get_year() 
              << std::setw(30) << std::right << trav->data.get_emissions() << std::endl;
    std::cout << std::endl;
}

/**
 * Deletes nodes in stack
*/
void StackCountry::delete_stack() {
    CountryNode* current = this->head;
    while (current != nullptr) {
        CountryNode* del = current;
        current = current->next;
        delete del;
    }
    this->head = nullptr;
}

/**
 * Outputs data to csv file
*/
void StackCountry::offload_data(std::ofstream& off) {
    off.open("save.csv");
    off << "Country" << "," << "Year" << "," << "Emissions" << std::endl;
    CountryNode* trav = this->head;
    while (trav != nullptr) {
        off << trav->data.get_name() << "," << trav->data.get_year() << "," << trav->data.get_emissions();
        if (trav->next != nullptr) {
            std::cout << std::endl;
        }
        trav = trav->next;
    }
}