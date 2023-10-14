#ifndef COUNTRYNODE_H
#define COUNTRYNODE_H

#include "country.h"

struct CountryNode {
    Country data;
    CountryNode* next = nullptr;
};

#endif