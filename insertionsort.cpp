#include <iostream>

#include "insertionsort.h"

bool customer_criteria_array(Customer* arr, Customer next, int index, char choice) {
    switch(choice) {
        case 'A' :
            return arr[index - 1].get_household_income() > next.get_household_income();
        case 'B':
            return arr[index - 1].get_credit_score() > next.get_credit_score();
        case 'C':
            return arr[index - 1].get_total_sales() > next.get_total_sales();
        default:
            return false;
    }
}

bool country_criteria_array(Country* arr, Country next, int index, char choice) {
    switch(choice) {
        case 'A':
            return arr[index - 1].get_emissions() > next.get_emissions();
        case 'B':
            return arr[index - 1].get_population() > next.get_population();
        case 'C':
            return arr[index - 1].get_area() > next.get_area();
        default:
            return false;
    }
}


bool customer_head_ptr_check(CustomerNode* head,CustomerNode* new_node, char choice) {
    switch(choice) {
        case 'A' :
            return head->data.get_household_income() >= new_node->data.get_household_income();
        case 'B':
            return head->data.get_credit_score() >= new_node->data.get_credit_score();
        case 'C':
            return head->data.get_total_sales() >= new_node->data.get_total_sales();
        default:
            return false;
    }
}

bool customer_curr_ptr_check(CustomerNode* curr,CustomerNode* new_node, char choice) {
    switch(choice) {
        case 'A' :
            return curr->next->data.get_household_income() < new_node->data.get_household_income();
        case 'B':
            return curr->next->data.get_credit_score() < new_node->data.get_credit_score();
        case 'C':
            return curr->next->data.get_total_sales() < new_node->data.get_total_sales();
        default:
            return false;
    }
}

bool country_head_ptr_check(CountryNode*head, CountryNode* new_node, char choice) {
    switch(choice) {
        case 'A':
            return head->data.get_emissions() >= new_node->data.get_emissions();
        case 'B':
            return head->data.get_population() >= new_node->data.get_population();
        case 'C':
            return head->data.get_area() >= new_node->data.get_area();
        default:
            return false;
    }
}

bool country_curr_ptr_check(CountryNode*curr, CountryNode* new_node, char choice) {
    switch(choice) {
        case 'A':
            return curr->next->data.get_emissions() < new_node->data.get_emissions();
        case 'B':
            return curr->next->data.get_population() < new_node->data.get_population();
        case 'C':
            return curr->next->data.get_area() < new_node->data.get_area();
        default:
            return false;
    }
}

void sorted_insert_customer(CustomerNode*& headref, CustomerNode* new_node, char choice) {
    if (headref == nullptr || customer_head_ptr_check(headref,new_node,choice)) {
        new_node->next = headref;
        headref = new_node;
    }
    else {
        CustomerNode* current = headref;
        while (current->next != nullptr && customer_curr_ptr_check(current,new_node,choice)) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void customer_sort_list(CustomerList& customer, char choice) {
    CustomerNode* sorted = nullptr;
    CustomerNode* curr = customer.first;
    while (curr != nullptr) {
        CustomerNode* next = curr->next;
        sorted_insert_customer(sorted,curr,choice);
        curr = next;
    }
    customer.first = sorted;
}

void sorted_insert_country(CountryNode *&headref, CountryNode* new_node, char choice) {
    if (headref == nullptr || country_head_ptr_check(headref, new_node, choice)) {
        new_node->next = headref;
        headref = new_node;
    }
    else {
        CountryNode* current = headref;
        while (current->next != nullptr && country_curr_ptr_check(current,new_node,choice)) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void country_sort_list(CountryList& country, char choice) {
    CountryNode* sorted = nullptr;
    CountryNode* curr = country.first;
    while (curr != nullptr) {
        CountryNode* next = curr->next;
        sorted_insert_country(sorted,curr,choice);
        curr = next;
    }
    country.first = sorted;
}




void customer_sort_array(Customer* arr, int index, char choice) {
    for (int i = 1; i < index; i++) {
        Customer next = arr[i];
        int j = i;
        while (j > 0 && customer_criteria_array(arr, next, j, choice)) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = next;
    }
}

void country_sort_array(Country* arr, int index, char choice) {
    for (int i = 1; i < index; i++) {
        Country next = arr[i];
        int j = i;
        while (j > 0 && country_criteria_array(arr, next, j, choice)) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = next;
    }
}

