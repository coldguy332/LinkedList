#include "stackcustomer.h"

/**
 * Stack default constructor
*/
StackCustomer::StackCustomer() {
    this->head = nullptr;
}

/**
 * Pushes objects in order
 * ONLY DO THIS ONCE
*/
void StackCustomer::push_in_order(Customer data) {
    CustomerNode* newnode = new CustomerNode; //creates a new node
    newnode->data = data; //new node takes in data
    if (this->head == nullptr) { //if head is null, new node becomes head
        this->head = newnode;
    }
    else {
        //if newnode is greater than head, newnode becomes new head
        if (newnode->data.get_serialized_date() > head->data.get_serialized_date()) {
            newnode->next = head;
            head = newnode;;
        }
        else {
            CustomerNode* trav = head; //ptr to head traverses until it's value is greater than newnode
            while (trav->next != nullptr && trav->next->data.get_serialized_date() > newnode->data.get_serialized_date()) {
                trav = trav->next;
            }
            CustomerNode* temp = trav->next;
            trav->next = newnode; //trav points to newnode
            newnode->next = temp; //newnode points to trav->next
        } 
    }
}


/**
 * Pushing one object to stack
*/
void StackCustomer::push(Customer data) {
    CustomerNode* newnode = new CustomerNode;
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
void StackCustomer::pop() {
    if (head != nullptr) {
        CustomerNode* to_delete = head;
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
void StackCustomer::print() {
    CustomerNode* trav = this->head;
    while (trav->next != nullptr) {
        trav = trav->next;
    }
    std::cout << std::endl;
    std::cout << "Current head: " << this->head->data.get_first_name() + " " + this->head->data.get_last_name() << std::setw(30) << std::right 
              << this->head->data.get_customer_since() << std::endl;
    std::cout << "        Tail: " << trav->data.get_first_name() + " " + trav->data.get_last_name() << std::setw(30) << std::right 
              << trav->data.get_customer_since() << std::endl;
    std::cout << std::endl;
}

/**
 * Deletes nodes in stack
*/
void StackCustomer::delete_stack() {
    CustomerNode* current = this->head;
    while (current != nullptr) {
        CustomerNode* del = current;
        current = current->next;
        delete del;
    }
    this->head = nullptr;
}
/**
 * Outputs data to csv file
*/
void StackCustomer::offload_data(std::ofstream& off) {
    off.open("save.csv");
    off << "First Name" << "," << "Last Name" << "," << "Customer since date" << std::endl;
    CustomerNode* trav = this->head;
    while (trav != nullptr) {
        off << trav->data.get_first_name() << "," << trav->data.get_last_name() << "," << trav->data.get_customer_since();
        if (trav->next != nullptr) {
            std::cout << std::endl;
        }
        trav = trav->next;
    }
}