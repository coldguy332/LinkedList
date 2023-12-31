//Created by Amal Afsal for Linked List lab on 10/11/23.

#ifndef DATAINPUT_H
#define DATAINPUT_H

#include <iostream>
#include <fstream>
#include <sstream>

#include "prompt.h"
#include "customerlist.h"
#include "countrylist.h"
#include "customer.h"
#include "country.h"
#include "stackcountry.h"
#include "stackcustomer.h"
#include "queuecustomer.h"
#include "queuecountry.h"


void data_input_customer();
void array_list_fill_customer(std::ifstream& in_file, Customer *arr, int index, CustomerList*& customer);


void data_input_country();
void array_list_fill_country(std::ifstream& in_file, Country* arr, int index, CountryList*& customer);


int line_counter(std::ifstream& in_file);
void quoted_field(std::stringstream& ss, std::string& temp_string);
void density_check(std::string& density);
void unknown_checker(std::string& emissions, std::string& population, std::string& area);

void stack_fill(char choice);
void stack_fill_customer(StackCustomer*& customer, std::ifstream& in_file);
void stack_fill_country(StackCountry*& country, std::ifstream& in_file);

void queue_fill(char choice);
void queue_fill_customer(QueueCustomer*& customer, std::ifstream& in_file);
void queue_fill_country(QueueCountry*& country, std::ifstream& in_file);

#endif