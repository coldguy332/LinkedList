#include "prompt.h"

void welcome_prompt() {
    std::cout << "Hello. This program takes in data from two datasets, sorts them in a linked list and array by various criteria, and creates " << 
                "stacks and queues that show their significance in real world cases." << std::endl;
	std::cout << "Would you like to continue(Y/n):" ;
	char choice;
	std::cin >> choice;
	if (choice == 'N' || choice == 'n') {
		exit(0); //Quits program
	} 
    if (choice == 'Y' || choice == 'y') {
        choosing_dataset();
    }
}

void choose_criteria_customer(Customer* arr, CustomerList customer, int index) {
	char choice;
	std::cout << "You will be given three criteria to sort these customer by:" << std::endl 
			  << "A) Household Income ; Reasoning: To see how much money they truly earn " << std::endl 
			  << "B) Credit Score; Reasoning: To see their buying capability" << std::endl 
			  << "C) Total Sales; Reasoning: To see how much they have bought from our company" << std::endl;
	std::cout << "What option would you like to choose:" ;
	std::cin >> choice;
}

void choose_criteria_country(Country* arr, CountryList country, int index) {
	char choice;
	std::cout << "You will be given three crieteria to sort these countries by:" << std::endl 
			  << "A) Emissions ; Reasoning: to see which countries produce the least and most emissions" << std::endl
			  << "B) Population; Reasoning: to see the correlation of population and emissions" << std::endl
			  << "C) Area; Reasoning: to see the correlation of land area and emissions" << std::endl;
	std::cout << "What option would you like to choose:" ;
	std::cin >> choice;

	country_sort_list(country, choice);
	country.temp_print();
}