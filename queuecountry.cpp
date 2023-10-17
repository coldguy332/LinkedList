#include "queuecountry.h"

/**
 * Defauly constructor for a Queue made for country
*/
QueueCountry::QueueCountry() {
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
void QueueCountry::push_back_in_order(Country data) {
    CountryNode* newnode = new CountryNode; //creating new node 
    newnode->data = data; //newnode takes in data
    if (this->head == nullptr) { //if list hasn't been created, head becomes newnode
        this->head = newnode;
        this->tail = newnode;
    }
    else {
        //Head will change if newnode is less than head
        if (newnode->data.get_year() < head->data.get_year()) { 
            newnode->next = head;
            head = newnode;
        }
        else {
            CountryNode* trav = head; //Node meant to be traversing through list
            //trav traverses until it is less than newnode
            while (trav->next != nullptr && trav->next->data.get_year() < newnode->data.get_year()) {
                trav = trav->next;
            }
            //if trav reaches all the way to the tail, newnode becomes new tail
            if (trav == tail) {
                tail->next = newnode;
                tail = newnode;
            }
            else { //else the newnode reaches it;s right position
                CountryNode* temp = trav->next;
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
void QueueCountry::push_back(Country data) {
    CountryNode* newnode = new CountryNode;
    newnode->data = data;
    if (tail == nullptr) { //checks if list hasn't been created yet
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
void QueueCountry::pop_front() {
    if (head != nullptr) { //Checks if list actually exists
        CountryNode* to_delete = head; //temp ptr to the head
        head = head->next; //head is now it's next-ptr
        delete to_delete; //head gets deleted
    }
    else {
        std::cout << std::endl;
        std::cout << "Queue is empty." << std::endl; //incase queue is empty
    }
}

/**
 * Prints object information
*/
void QueueCountry::print() {
    std::cout << std::endl;
    std::cout << "Current head: " << this->head->data.get_name() << std::setw(20) << std::right<< this->head->data.get_year(); 
    std::cout << std::setw(20) << std::right << this->head->data.get_emissions() << std::endl;
    std::cout << "        Tail: " << this->tail->data.get_name() << std::setw(20) << std::right << this->tail->data.get_year(); 
    std::cout << std::setw(20) << std::right << this->tail->data.get_emissions() << std::endl;
    std::cout << std::endl;
}

/**
 * Deletes nodes from queue
*/
void QueueCountry::delete_queue() {
    CountryNode* current = this->head;
    while (current != nullptr) {
        CountryNode* del = current;
        current = current->next;
        delete del;
    }
    this->head = nullptr;
    this->tail = nullptr;
}

/**
 * Outputs data in csv format
*/
void QueueCountry::offload_data(std::ofstream& off) {
    off.open("save.csv");
    off << "Country Name" << "," << "Year" << "," << "Emissions" << std::endl;
    CountryNode* trav = this->head;
    while (trav != nullptr) {
        off << trav->data.get_name() << "," << trav->data.get_year() << "," << trav->data.get_emissions();
        if (trav->next != nullptr) {
            std::cout << std::endl;
        }
        trav = trav->next;
    }
}