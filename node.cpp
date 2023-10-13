#include "node.h"

Node::Node() {
    this->next = nullptr;
}

CustomerNode::CustomerNode(Customer newcustomer) : Node() {
    this->newcustomer = newcustomer;
}

CountryNode::CountryNode(Country newcountry) : Node() {
    this->newcountry = newcountry;
}