#ifndef STACKCOUNTRY_H
#define STACKCOUNTRY_H

#include <iostream>

#include "country.h"
#include "countrynode.h"

//Will hold most recent emissions
struct StackCountry {
    
    StackCountry();

    void push_in_order(Country data);

    void push(Country data);
    void pop();

    CountryNode* head;

};


#endif