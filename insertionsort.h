#ifndef INSERTIONSORT_H
#define INERSTIONSORT_H

#include "customer.h"
#include "customerlist.h"
#include "country.h"
#include "countrylist.h"

bool customer_criteria_array(Customer* arr, Customer next, int index, char choice);
bool country_criteria_array(Country* arr, Country next, int index, char choice);

void customer_sort_array(Customer* arr, int index, char choice);
void country_sort_array(Country* arr, int index, char choice);

void customer_sort_list(CustomerList customer, char choice);
void country_sort_list(CountryList country, char choice);




#endif