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


void customer_sort_array(Customer* arr, int index, char choice) {
    for (int i = 1; i < index; i++) {
        Customer next = arr[i];
        int j = i;
        while (j > 0 && customer_criteria_array(arr, next, index, choice)) {
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
        while (j > 0 && country_criteria_array(arr, next, index, choice)) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = next;
    }
}