#ifndef COUNTRYLIST_H
#define COUNTRYLIST_H

#include "country.h"
#include "countrynode.h"

struct CountryList {

    void push_back_country(Country data);
    CountryNode* first;
    CountryNode* last;

};

#endif