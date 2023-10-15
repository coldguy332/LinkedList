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

	insertion_sort_customer(arr, index, customer, choice);

	choose_displayed_data_customer(arr, index);
}

void choose_criteria_country(Country* arr, CountryList country, int index) {
	char choice;
	std::cout << "You will be given three crieteria to sort these countries by:" << std::endl 
			  << "A) Emissions ; Reasoning: to see which countries produce the least and most emissions" << std::endl
			  << "B) Population; Reasoning: to see the correlation of population and emissions" << std::endl
			  << "C) Area; Reasoning: to see the correlation of land area and emissions" << std::endl;
	std::cout << "What option would you like to choose:" ;
	std::cin >> choice;

	insertion_sort_country(arr, index, country, choice);
	for (int i = 0; i < 50; i++) {
		std::cout << arr[i].get_emissions() << std::endl;
	}

	//choose_displayed_data_country(arr, index, choice);
}

void choose_displayed_data_customer(Customer* arr, int index) {
	char choice;

	std::cout << std::endl;
	std::cout << "Sorting has been completed. Would you like to display Top 50 or Bottom 50 of the sorted items(A/B):" ;
	std::cin >> choice;
	display_customer_data(arr, index, choice);
}

void choose_displayed_data_country(Country* arr, int index, char criteria) {
	char choice;

	std::cout << std::endl;
	std::cout << "Sorting has been completed. Would you like to display Top 50 or Bottom 50 of the sorted items(A/B):" ;
	std::cin >> choice;
	display_country_data(arr, index, choice, criteria);
}