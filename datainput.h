#ifndef DATAINPUT_H
#define DATAINPUT_H

#include <iostream>
#include <fstream>
#include <sstream>

#include "customerlist.h"
#include "countrylist.h"
#include "customer.h"
#include "country.h"

void choosing_dataset();

void datainput_customer();
void array_list_fill_customer(std::ifstream& in_file, Customer *arr, int index, CustomerList& customer);


void datainput_country();
void array_list_fill_country(std::ifstream& in_file, Country* arr, int index, CountryList& customer);


int line_counter(std::ifstream& in_file);
void quoted_field(std::stringstream& ss, std::string& temp_string);
void density_check(std::string& density);
void unknown_checker(std::string& emissions, std::string& population, std::string& area);

#endif