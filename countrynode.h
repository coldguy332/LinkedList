//Created by Amal Afsal for Linked List lab on 10/10/23.

#ifndef COUNTRYNODE_H
#define COUNTRYNODE_H

#include "country.h"

/**
 * Linked list node for country objects
*/
struct CountryNode {
    Country data;
    CountryNode* next = nullptr;
};

#endif