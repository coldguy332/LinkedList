//Created by Amal Afsal for Linked List lab on 10/12/23.

#ifndef SORTER_H
#define SORTER_H

#include "country.h"
#include "customer.h"
#include "insertionsort.h"
#include "customerlist.h"
#include "countrylist.h"
#include "displaydata.h"

#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

void copy_country_array(Country* arr_one, Country* arr_two, int index);
void copy_country_list(CountryList*& list_one, CountryList*& list_two);

void copy_customer_array(Customer* arr_one, Customer* arr_two, int index);
void copy_customer_list(CustomerList*& list_one, CustomerList*& list_two);

void launch_customer_insertionsort_array(Customer* arr, int size, char choice);
void launch_customer_insertionsort_list(CustomerList*& list, char choice);

void launch_country_insertionsort_array(Country* arr, int size, char choice);
void launch_country_insertionsort_list(CountryList*& list, char choice);

void insertion_sort_country(Country* arr, int size, CountryList*& country, char choice);
void insertion_sort_customer(Customer* arr, int size, CustomerList*& customer, char choice);


#endif