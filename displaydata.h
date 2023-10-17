//Created by Amal Afsal for Linked List lab on 10/14/23.

#ifndef DISPLAYDATA_H
#define DISPLAYDATA_H

#include <iostream>
#include <iomanip>

#include "customer.h"
#include "country.h"


std::string get_criteria_customer(char choice);
std::string get_criteria_country(char choice);

void display_time_borders();
void display_sorted_times(std::string criteria, double time, std::string datastructure);

void display_sorted_customer_borders();
void display_sorted_country_borders();

void display_customer_data(Customer* arr, int index, char choice);
void display_country_data(Country* arr,int index, char choice, char criteria);




#endif