#ifndef STACKCOUNTRY_H
#define STACKCOUNTRY_H

#include <iostream>
#include <iomanip>
#include <fstream>

#include "country.h"
#include "countrynode.h"

//Will hold most recent emissions
struct StackCountry {
    
    StackCountry();

    void push_in_order(Country data);

    void push(Country data);
    void pop();

    void print();

    void delete_stack();

    void offload_data(std::ofstream& off);

    CountryNode* head;

};


#endif