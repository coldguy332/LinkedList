//Created by Amal Afsal for Linked List lab on 10/12/23.

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "customer.h"
#include "customerlist.h"
#include "country.h"
#include "countrylist.h"

bool customer_criteria_array(Customer* arr, Customer next, int index, char choice); //Implemented
bool country_criteria_array(Country* arr, Country next, int index, char choice); //Implemented

bool customer_head_ptr_check(CustomerNode* head,CustomerNode* new_node, char choice); //Implemented
bool customer_curr_ptr_check(CustomerNode* curr,CustomerNode* new_node, char choice); //Implemented
bool country_head_ptr_check(CountryNode*head, CountryNode* new_node, char choice); //Implemented 
bool country_curr_ptr_check(CountryNode*curr, CountryNode* new_node, char choice); //Implemented


void customer_sort_array(Customer* arr, int index, char choice); //Implemented
void country_sort_array(Country* arr, int index, char choice); //Implemented

void customer_sort_list(CustomerList*& customer, char choice); //Implemented
void sorted_insert_customer(CustomerNode *&headref, CustomerNode* new_node, char choice); //Implemented


void country_sort_list(CountryList*& country, char choice); //Implemented 
void sorted_insert_country(CountryNode *&headref, CountryNode* new_node, char choice); //Implemented




#endif