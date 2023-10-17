#include "queuecustomer.h"

/**
 * Default constructor for a Queue
*/
QueueCustomer::QueueCustomer() {
    this->head = nullptr;
    this->tail = nullptr;
}

/**
 * Pushes objects into queue in order
 * ONLY MEANT TO BE USED WHEN INPUTTING OBJECTS FROM CSV
 * also reallllllllly slow if using big csv files
 * use smaller files plz
 * citing teamwork lab while also adding minor adjustments
*/
void QueueCustomer::push_back_in_order(Customer data) {
    CustomerNode* newnode = new CustomerNode; //creating new node 
    newnode->data = data; //newnode takes in data
    if (this->head == nullptr) {//if list hasn't been created, head becomes newnode
        this->head = newnode;
        this->tail = newnode;
    }
    else {
        //Head will change if newnode is less than head
        if (newnode->data.get_total_sales() > head->data.get_total_sales()) {
            newnode->next = head;
            head = newnode;
        }
        else {
            CustomerNode* trav = head; //Node meant to be traversing through list
            //trav traverses until it is less than newnode
            while (trav->next != nullptr && trav->next->data.get_total_sales() > newnode->data.get_total_sales()) {
                trav = trav->next;
            }
            //if trav reaches all the way to the tail, newnode becomes new tail
            if (trav == tail) {
                tail->next = newnode;
                tail = newnode;
            }
            else { //else the newnode reaches it;s right position
                CustomerNode* temp = trav->next;
                trav->next = newnode;
                newnode->next = temp;
            }
        }
    }
}

/**
 * Pushes back objects from the tail
 * (will pop from front)
*/
void QueueCustomer::push_back(Customer data) {
    CustomerNode* newnode = new CustomerNode;
    newnode->data = data;
    newnode->data = data;
    if (tail == nullptr) {
        head = newnode;
        tail = newnode;
    }
    else {
        tail->next = newnode;
        tail = newnode;
    }
}

/**
 * Removes object from the front
*/
void QueueCustomer::pop_front() {
    if (head != nullptr) {
        CustomerNode* to_delete = head;
        head = head->next;
        delete to_delete;
    }
    else {
        std::cout << std::endl;
        std::cout << "Queue is empty." << std::endl;
    }
}

/**
 * Prints object information
*/
void QueueCustomer::print() {
    std::cout << std::endl;
    std::cout << "Current head: " << this->head->data.get_first_name() + " " + this->head->data.get_last_name() << std::setw(10) << std::right 
              << this->head->data.get_total_sales() << std::endl;
    std::cout << "        Tail: " << this->tail->data.get_first_name() + " " + this->tail->data.get_last_name() << std::setw(10) << std::right
              << this->tail->data.get_total_sales() << std::endl;
    std::cout << std::endl;
}

/**
 * Deletes nodes from queue
*/
void QueueCustomer::delete_queue() {
    CustomerNode* current = this->head;
    while (current != nullptr) {
        CustomerNode* del = current;
        current = current->next;
        delete del;
    }
    this->head = nullptr;
    this->tail = nullptr;
}

/**
 * Outputs data in csv format
*/
void QueueCustomer::offload_data(std::ofstream& off) {
    off.open("save.csv");
    off << "First Name" << "," << "Last Name" << "," << "Total Sales" << std::endl;
    CustomerNode* trav = this->head;
    while (trav != nullptr) {
        off << trav->data.get_first_name() << "," << trav->data.get_last_name() << "," << trav->data.get_total_sales();
        if (trav->next != nullptr) {
            std::cout << std::endl;
        }
        trav = trav->next;
    }
}