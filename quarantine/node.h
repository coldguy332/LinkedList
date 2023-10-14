#ifndef NODE_H
#define NODE_H

#include <iostream>

#include "list.h"
#include "country.h"
#include "customer.h"

class Node{
    public:
        Node();
    private:
        Node* next;
friend class List;
};

class CustomerNode : public Node {
    public:
        CustomerNode(Customer newcustomer);
    private:
        Customer newcustomer;
        
};

class CountryNode: public Node {
    public:
        CountryNode(Country newcountry);
    private:
        Country newcountry;
};



#endif