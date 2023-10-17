#ifndef PROMPT_H
#define PROMPT_H

#include <iostream>
#include <fstream>

#include "datainput.h"
#include "sorter.h"
#include "displaydata.h"
#include "queuecustomer.h"
#include "queuecountry.h"
#include "stackcountry.h"
#include "stackcustomer.h"

void welcome_prompt();
void choose_criteria_customer(Customer* arr, CustomerList customer, int index);
void choose_criteria_country(Country* arr, CountryList country, int index);

void choose_displayed_data_customer(Customer* arr, int index);
void choose_displayed_data_country(Country* arr, int index, char criteria);

void choose_stack_or_queue();
void choose_specific_stack();
void choose_specific_queue();

void customer_stack_interaction(StackCustomer*& customer);
void country_stack_interaction(StackCountry*& country);

void customer_queue_interaction(QueueCustomer*& customer);
void country_queue_interaction(QueueCountry*& country);

void save_stack_customer(StackCustomer*& customer);
void save_stack_country(StackCountry*& country);
void save_queue_customer(QueueCustomer*& customer);
void save_country_customer(QueueCountry*& country);

#endif