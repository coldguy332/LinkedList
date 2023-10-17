#ifndef PROMPT_H
#define PROMPT_H

#include <iostream>

#include "datainput.h"
#include "sorter.h"
#include "displaydata.h"

void welcome_prompt();
void choose_criteria_customer(Customer* arr, CustomerList customer, int index);
void choose_criteria_country(Country* arr, CountryList country, int index);

void choose_displayed_data_customer(Customer* arr, int index);
void choose_displayed_data_country(Country* arr, int index, char criteria);

void choose_stack_or_queue();
void choose_specific_stack();
void choose_specific_queue();

#endif