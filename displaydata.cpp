#include "displaydata.h"

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

void display_borders() {
    std::cout << std::setw(20) << std::left << "Sorted Criteria";
    std::cout << std::setw(1) << std::left << " ";
    std::cout << std::setw(20) << std::right << "Time" << std::endl;
    for (int i = 0; i < 41; i++) {
        std::cout << "=";
    }
    std::cout << std::endl;
}

void display_sorted_times(std::string criteria, double time) {
    std::cout << std::setw(20) << std::left << criteria;
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::right << time << std::endl;
}