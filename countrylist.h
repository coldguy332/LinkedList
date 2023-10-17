//Created by Amal Afsal for Linked lab on 9/10/23.

#ifndef COUNTRYLIST_H
#define COUNTRYLIST_H

#include "country.h"
#include "countrynode.h"

struct CountryList {

    void push_back_country(Country data);
    void delete_list();
    CountryNode* first = nullptr;
    CountryNode* last = nullptr;

};

#endif