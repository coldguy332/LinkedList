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
	choose_stack_or_queue();
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
	choose_displayed_data_country(arr, index, choice);
	choose_stack_or_queue();
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

void choose_stack_or_queue() {
	char choice;
	std::cout << std::endl;
	std::cout << "Thank you for using the sorting functionality of our program. We will now move on." << std::endl;
	std::cout << "You now have the ability to create a stack and a queue. Both in this case will be linked lists but with some differences." << std::endl;
	std::cout << "Stacks: A stack inserts and/or deletes elements at one side of the list (typically called the top)." << std::endl;
	std::cout << "Queues: A queue inserts one element on one side and another element at the other side." << std::endl;
	std::cout << "In this program, we are giving you the option to experience utilizing a stack or queue." << std::endl;
	std::cout << "Would you like to use" << std::endl << "A) Stack" << std::endl << "B) Queue" << std::endl;
	std::cin >> choice;
}

void choose_specific_stack() {
	char choice;
	std::cout << std::endl;
	std::cout << "Pick one of the cases below: " << std::endl;
	std::cout << "A) Company which has a list of least to most loyal customers. Employee can add or remove most recent customer" <<std::endl;
	std::cout << "B) United Nations has a list of least to most recent emission reports from countries. Employee can add or remove" 
			  << " most recent listing" << std::endl;
	std::cout << "Please pick one: " ;
	std::cin >> choice;
} 

void choose_specific_queue() {
	char choice;
	std::cout << std::endl;
	std::cout << "Pick one of the cases below: " << std::endl;
	std::cout << "A) Company has a list of least to most spending customers. Employee adds new customers and removes most spending customers" 
			  << " which signifies that they will recieve a thank-you card." << std::endl;
	std::cout << "B) United Nations once again has a list of least to most recent emission reports from countries. Due to new policies" 
			  << " , older emission reports can be purged. Employee has the ability to delete old emissions reports while adding new ones" << std::endl;
	std::cout << "Please pick one: " ;
	std::cin >> choice;
}

void customer_stack_interaction(StackCustomer*& customer) {
	char choice;
	std::string temp_first_name ,temp_last_name, temp_date;
	bool persist = true;
	while (persist) {
		customer->print();
		std::cout << "Remove or add element (A/B): " ;
		if (choice == 'A' || choice == 'a') {
			customer->pop();
			customer->print();
		}
		else if (choice == 'B' || choice == 'b') {
			std::cout << std::endl << "Enter First Name:";
			std::cin >> temp_first_name;
			std::cout << std::endl << "Enter Lirst Name:";
			std::cin >> temp_last_name;
			std::cout << std::endl << "Enter Date of when customer first bought from us (mm/dd/yyyy): "; 
			std::cin >> temp_date;
			customer->push(Customer(temp_first_name,temp_last_name,temp_date));
			customer->print();
		}
		std::cout << "Continue modifying stack? (Y/n):";
		std::cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			continue;
		}
		if (choice == 'N' || choice == 'n') {
			persist = false;
		}
	}
}
void country_stack_interaction(StackCountry*& country) {
	char choice;
	std::string temp_country_name, temp_year, temp_emissions;
	bool persist = true;
	while (persist) {
		std::cout << "Remove or add element (A/B): " ;
		if (choice == 'A' || choice == 'a') {
			country->pop();
			country->print();
		}
		else if (choice == 'B' || choice == 'b') {
			std::cout << std::endl << "Enter Country Name:";
			std::cin >> temp_country_name;
			std::cout << std::endl << "Enter Year as of today:";
			std::cin >> temp_year;
			std::cout << std::endl << "Enter emissions of country: "; 
			std::cin >> temp_emissions;
			country->push(Country(stoi(temp_year),temp_country_name,stold(temp_emissions)));
			country->print();
		}
		std::cout << "Continue modifying stack? (Y/n):";
		std::cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			continue;
		}
		if (choice == 'N' || choice == 'n') {
			persist = false;
		}
	}
}

void customer_queue_interaction(QueueCustomer*& customer) {
	char choice;
	std::string temp_first_name ,temp_last_name, temp_total_sales;
	bool persist = true;
	while (persist) {
		customer->print();
		std::cout << "Remove or add element (A/B): " ;
		if (choice == 'A' || choice == 'a') {
			customer->pop_front();
			customer->print();
		}
		else if (choice == 'B' || choice == 'b') {
			std::cout << std::endl << "Enter First Name:";
			std::cin >> temp_first_name;
			std::cout << std::endl << "Enter Lirst Name:";
			std::cin >> temp_last_name;
			std::cout << std::endl << "Enter Total Sales (must be less than previous): "; 
			std::cin >> temp_total_sales;
			customer->push_back(Customer(temp_first_name,temp_last_name,temp_total_sales));
			customer->print();
		}
		std::cout << "Continue modifying stack? (Y/n):";
		std::cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			continue;
		}
		if (choice == 'N' || choice == 'n') {
			persist = false;
		}
	}
}
void country_queue_interaction(QueueCountry*& country) {
	char choice;
	std::string temp_country_name, temp_year, temp_emissions;
	bool persist = true;
	while (persist) {
		std::cout << "Remove or add element (A/B): " ;
		if (choice == 'A' || choice == 'a') {
			country->pop_front();
			country->print();
		}
		else if (choice == 'B' || choice == 'b') {
			std::cout << std::endl << "Enter Country Name:";
			std::cin >> temp_country_name;
			std::cout << std::endl << "Enter Year as of today:";
			std::cin >> temp_year;
			std::cout << std::endl << "Enter emissions of country: "; 
			std::cin >> temp_emissions;
			country->push_back(Country(stoi(temp_year),temp_country_name,stold(temp_emissions)));
			country->print();
		}
		std::cout << "Continue modifying stack? (Y/n):";
		std::cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			continue;
		}
		if (choice == 'N' || choice == 'n') {
			persist = false;
		}
	}
}