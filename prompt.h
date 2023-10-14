#ifndef PROMPT_H
#define PROMPT_H

#include <iostream>

#include "datainput.h"

void welcome_prompt();
void choose_criteria_customer(Customer* arr, CustomerList customer, int index);
void choose_criteria_country(Country* arr, CountryList country, int index);

#endif