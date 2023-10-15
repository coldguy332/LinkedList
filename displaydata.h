#ifndef DISPLAYDATA_H
#define DISPLAYDATA_H

#include <iostream>
#include <iomanip>

#include "customer.h"
#include "customerlist.h"

std::string get_criteria_customer(char choice);
std::string get_criteria_country(char choice);

void display_borders();
void display_sorted_times(std::string criteria, double time, std::string datastructure);


#endif