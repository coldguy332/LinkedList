#ifndef DATAINPUT_H
#define DATAINPUT_H

#include <iostream>
#include <fstream>
#include <sstream>

#include "list.h"
#include "customer.h"
#include "country.h"

void choosing_dataset();

void datainput_customer();
void array_fill_customer(std::ifstream& in_file, Customer *arr, int index, List customer);
void list_fill_customer(std::ifstream& in_file, List customer);

/*
void datainput_country();
void array_fill_country();
void list_fill_country();
*/

int line_counter(std::ifstream& in_file);
void quoted_field(std::stringstream& ss, std::string& temp_string);



#endif