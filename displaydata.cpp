#include "displaydata.h"

/**
 * Returns what criteria a customer list/array was sorted by
 * helper function
*/
std::string get_criteria_customer(char choice) {
    switch (choice) {
        case 'A':
            return "Household Income";
            break;
        case 'B':
            return "Credit Score";
            break;
        case 'C':
            return "Total Sales";
            break;
        default:
        	return "";
        	break;
    }
}

/**
 * Returns what criteria a country list/array was sorted by
 * helper function
*/
std::string get_criteria_country(char choice) {
    switch (choice) {
        case 'A':
            return "Emissions";
            break;
        case 'B':
            return "Population";
            break;
        case 'C':
            return "Area";
            break;
        default:
            return "";
            break;
    }
}

/**
 * Displays the border outlines for a table that displays sorting times of array and list
*/
void display_time_borders() {
    std::cout << std::endl;
    std::cout << std::setw(20) << std::left << "Sorted Criteria";
    std::cout << std::setw(1) << std::left << " ";
    std::cout << std::setw(20) << std::right << "Time";
    std::cout << std::setw(1) << std::right << " ";
    std::cout << std::setw(20) << std::right << "Data Struture" << std::endl;
    for (int i = 0; i < 62; i++) {
        std::cout << "="; //Creates a line under the wording
    }
    std::cout << std::endl;
}

/**
 * Displays the sorting times of a list/array
 * This comes under the time borders
*/
void display_sorted_times(std::string criteria, double time, std::string datastructure) {
    std::cout << std::setw(20) << std::left << criteria;
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::right << time;
    std::cout << std::setw(1) << std::right << " ";
    std::cout << std::setw(20) << std::right << datastructure << std::endl;
}

/**
 * Displays border information for a table that displays sorted information
*/
void display_sorted_customer_borders() {
    std::cout << std::endl;
    std::cout << std::setw(20) << std::left << "Household Income";
    std::cout << std::setw(1) << std::left << " ";
    std::cout << std::setw(20) << std::left << "Credit Score";
    std::cout << std::setw(1) << std::left << " ";
    std::cout << std::setw(20) << std::right << "Total Sales";
    std::cout << std::setw(1) << std::right << " ";
    std::cout << std::setw(20) << std::right << "Name" << std::endl;
    for (int i = 0; i < 83; i++) {
        std::cout << "="; //Creates a line under the wording
    }
    std::cout << std::endl;
}

/**
 * Displays border information for a table that displays sorted information
*/
void display_sorted_country_borders() {
    std::cout << std::endl;
    std::cout << std::setw(20) << std::left << "Emissions";
    std::cout << std::setw(1) << std::left << " ";
    std::cout << std::setw(20) << std::left << "Population";
    std::cout << std::setw(1) << std::left << " ";
    std::cout << std::setw(20) << std::right << "Area";
    std::cout << std::setw(1) << std::right << " ";
    std::cout << std::setw(20) << std::right << "Country Name" << std::endl;
    for (int i = 0; i < 83; i++) {
        std::cout << "=";
    }
    std::cout << std::endl;
}

/**
 * Displays sorted information and other relevant information for customer objects
*/
void display_customer_data(Customer* arr, int index, char choice) {
    display_sorted_customer_borders();
    if (choice == 'A') {
        for (int i = 0; i < 50; i++) { //Displays top 50 object information
            std::cout << std::setw(20) << std::left << arr[i].get_household_income();
            std::cout << std::setw(1) << std::left << " ";
            std::cout << std::setw(20) << std::left << arr[i].get_credit_score();
            std::cout << std::setw(1) << std::left << " ";
            std::cout << std::setw(20) << std::right << std::setprecision(2) << arr[i].get_total_sales();
            std::cout << std::setw(1) << std::right << " ";
            std::cout << std::setw(20) << std::right << arr[i].get_first_name() + " " + arr[i].get_last_name() << std::endl;
        }
    }
    if (choice == 'B') {
        for (int i = index - 50; i < index ; i++) { //Displays bottom 50 object information
            std::cout << std::setw(20) << std::left << arr[i].get_household_income();
            std::cout << std::setw(1) << std::left << " ";
            std::cout << std::setw(20) << std::left << arr[i].get_credit_score();
            std::cout << std::setw(1) << std::left << " ";
            std::cout << std::setw(20) << std::right << std::setprecision(2) << arr[i].get_total_sales();
            std::cout << std::setw(1) << std::right << " ";
            std::cout << std::setw(20) << std::right << arr[i].get_first_name() + " " + arr[i].get_last_name() << std::endl;
        }
    }
}

/**
 * Displays sorted and other relevant information for country objects
*/
void display_country_data(Country* arr,int index, char choice, char criteria) {
    display_sorted_country_borders();
    if (choice == 'A') { 
        int temp_index = 0;
        //This bit of code forces the program to skip over all the unknowns that have found their way to 
        //the top of the sorted list
        while (temp_index < index) { 
            if (arr[temp_index].get_data_member(criteria)) {
                temp_index++; //Index keeps increasing until there are no unknowns left
            }
            else {
                break;
            }
        }
        for (int i = temp_index; i < temp_index + 50; i++) { //Displays true top 50 sorted items
            std::cout << std::setw(20) << std::left << arr[i].get_emissions();
            std::cout << std::setw(1) << std::left << " ";
            std::cout << std::setw(20) << std::left << arr[i].get_population();
            std::cout << std::setw(1) << std::left << " ";
            std::cout << std::setw(20) << std::right << arr[i].get_area();
            std::cout << std::setw(1) << std::right << " ";
            std::cout << std::setw(20) << std::right << arr[i].get_name() << std::endl;
        }
    }
    if (choice == 'B') {
        for (int i = index - 50; i < index; i++) { //Displays bottom 50 sorted items
            std::cout << std::setw(20) << std::left << arr[i].get_emissions();
            std::cout << std::setw(1) << std::left << " ";
            std::cout << std::setw(20) << std::left << arr[i].get_population();
            std::cout << std::setw(1) << std::left << " ";
            std::cout << std::setw(20) << std::right << arr[i].get_area();
            std::cout << std::setw(1) << std::right << " ";
            std::cout << std::setw(20) << std::right << arr[i].get_name() << std::endl;
        }
    }
}
