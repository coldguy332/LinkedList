#include "prompt.h"

/**
 * Outputs welcome prompt
*/
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
        choosing_dataset(); //Lets user choose what to sort from
    }
}

/**
 * Prompt that outputs what dataset user can choose from
*/
void choosing_dataset() {
    char choice;
    std::cout << "You have two datasets to choose from:" << std::endl;
    std::cout << "A) A dataset of customers who create sales for your (hypothetical) company" << std::endl;
    std::cout << "B) A dataset of countries who produce CO2 emissions to the earth" <<std::endl;
    std::cout << "What dataset would you like to choose:" ;
    std::cin >> choice;
    if (choice == 'A' || choice == 'a') {
        data_input_customer(); //Inputs array and list with customers, check datainput.cpp
    }
    if (choice == 'B' || choice == 'b') {
        data_input_country(); //Inputs array and lists with countries, check datainput.cpp
    }

}


/**
 * Lets user choose what criteria to sort by for list and array
*/
void choose_criteria_customer(Customer* arr, CustomerList*& customer, int index) {
	char choice;
	std::cout << "You will be given three criteria to sort these customer by:" << std::endl 
			  << "A) Household Income ; Reasoning: To see how much money they truly earn " << std::endl 
			  << "B) Credit Score; Reasoning: To see their buying capability" << std::endl 
			  << "C) Total Sales; Reasoning: To see how much they have bought from our company" << std::endl;
	std::cout << "What option would you like to choose:" ;
	std::cin >> choice;

	insertion_sort_customer(arr, index, customer, choice); //Sorts list and array , sorter.cpp
	choose_displayed_data_customer(arr, index); //displays either top or bottom 50 of sorted list;
	choose_stack_or_queue(); //Creates a stack or queue
}

/**
 * Lets user choose what criteria to sort by for list and array
*/
void choose_criteria_country(Country* arr, CountryList*& country, int index) {
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

/**
 * Displays top 50 or bottom 50 of sorted list
*/
void choose_displayed_data_customer(Customer* arr, int index) {
	char choice;

	std::cout << std::endl;
	std::cout << "Sorting has been completed. Would you like to display Top 50 or Bottom 50 of the sorted items(A/B):" ;
	std::cin >> choice;
	display_customer_data(arr, index, choice);
}

/**
 * Displays top 50 or bottom 50 of sorted list
*/
void choose_displayed_data_country(Country* arr, int index, char criteria) {
	char choice;

	std::cout << std::endl;
	std::cout << "Sorting has been completed. Would you like to display Top 50 or Bottom 50 of the sorted items(A/B):" ;
	std::cin >> choice;
	display_country_data(arr, index, choice, criteria);
}

/**
 * Allows user to create stack or queue
*/
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
	if (choice == 'A' || choice == 'a') {
		choose_specific_stack(); //Allows user to create more specific stack
	}
	if (choice == 'B' || choice == 'b') {
		choose_specific_queue(); //Allows user to create more specific queue
	}

}

/**
 *  Allows user to choose specific stack
*/
void choose_specific_stack() {
	char choice;
	std::cout << std::endl;
	std::cout << "Pick one of the cases below: " << std::endl;
	std::cout << "A) Company which has a list of least to most loyal customers. Employee can add or remove most recent customer" <<std::endl;
	std::cout << "B) United Nations has a list of least to most recent emission reports from countries. Employee can add or remove" 
			  << " most recent listing" << std::endl;
	std::cout << "Please pick one: " ;
	std::cin >> choice;
	stack_fill(choice); //Creates stack based off the criteria
} 

/**
 *  Allows user to choose specific queue
*/
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
	queue_fill(choice); //Create queue based off criteria
}

/**
 * Allows user to interact with stack
*/
void customer_stack_interaction(StackCustomer*& customer) {
	char choice;
	std::string temp_first_name ,temp_last_name, temp_date;
	bool persist = true;
	while (persist) {
		customer->print(); 
		std::cout << "Remove or add element (A/B): " ;
		std::cin >> choice;
		if (choice == 'A' || choice == 'a') {
			customer->pop(); //Removes object
			customer->print(); //Prints to show change
		}
		else if (choice == 'B' || choice == 'b') {
			std::cout << std::endl << "Enter First Name:";
			std::cin >> temp_first_name;
			std::cout << std::endl << "Enter Lirst Name:";
			std::cin >> temp_last_name;
			std::cout << std::endl << "Enter Date of when customer first bought from us (mm/dd/yyyy): "; 
			std::cin >> temp_date;
			customer->push(Customer(temp_first_name,temp_last_name,temp_date));
			customer->print(); //Creates a new object and prints new information
		}
		std::cout << "Continue modifying stack? (Y/n):"; //User given the option to keep modifying stack
		std::cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			continue;
		}
		if (choice == 'N' || choice == 'n') {
			persist = false;
		}
	}
	save_stack_customer(customer); //Customer given option to save stack
}

/**
 * Allows user to interact with stack
*/
void country_stack_interaction(StackCountry*& country) {
	char choice;
	std::string temp_country_name, temp_year, temp_emissions;
	bool persist = true;
	while (persist) {
		country->print();
		std::cout << "Remove or add element (A/B): " ;
		std::cin >> choice;
		if (choice == 'A' || choice == 'a') {
			country->pop(); //Removes object
			country->print(); //Prints to show change
		}
		else if (choice == 'B' || choice == 'b') {
			std::cout << std::endl << "Enter Country Name:";
			std::cin >> temp_country_name;
			std::cout << std::endl << "Enter Year as of today:";
			std::cin >> temp_year;
			std::cout << std::endl << "Enter emissions of country: "; 
			std::cin >> temp_emissions;
			country->push(Country(stoi(temp_year),temp_country_name,stold(temp_emissions)));
			country->print();//Creates a new object and prints new information
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
	save_stack_country(country);//Customer given option to save stack
}

/**
 * User can interact with queue
*/
void customer_queue_interaction(QueueCustomer*& customer) {
	char choice;
	std::string temp_first_name ,temp_last_name, temp_total_sales;
	bool persist = true;
	while (persist) {
		customer->print();
		std::cout << "Remove or add element (A/B): " ;
		std::cin >> choice;
		if (choice == 'A' || choice == 'a') { //Can either remove or add to the queue
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
			customer->push_back(Customer(temp_first_name,temp_last_name,stod(temp_total_sales)));
			customer->print();
		}
		std::cout << "Continue modifying queue? (Y/n):"; //User given the option to keep modifiying queue
		std::cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			continue;
		}
		if (choice == 'N' || choice == 'n') {
			persist = false;
		}
	}
	save_queue_customer(customer);
}
/**
 * User can interact with queue
*/
void country_queue_interaction(QueueCountry*& country) {
	char choice;
	std::string temp_country_name, temp_year, temp_emissions;
	bool persist = true;
	while (persist) {
		country->print();
		std::cout << "Remove or add element (A/B): " ;
		std::cin >> choice;
		if (choice == 'A' || choice == 'a') {//Can either remove or add to the queue
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
		std::cout << "Continue modifying queue? (Y/n):";//User given the option to keep modifiying queue
		std::cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			continue;
		}
		if (choice == 'N' || choice == 'n') {
			persist = false;
		}
	}
	save_queue_country(country);
}

/**
 * Final part of program
 * User can save stack/queue, quit, or reuse the program
*/
void save_stack_customer(StackCustomer*& customer) {
	char choice;
	std::cout << std::endl;
	std::cout << "Would you like to save your stack (Y/n):";
	if (choice == 'Y' || choice == 'y') {
		std::ofstream off_file;
		customer->offload_data(off_file);
		customer->delete_stack();
		delete customer;
	}
	std::cout << std::endl;
	std::cout << "Would you like to re-run the program? (Y/n):";
	std::cin >> choice;
	if (choice == 'Y' || choice == 'y') {
		welcome_prompt();
	}
	else if (choice == 'N' || choice == 'n') {
		exit(0);
	}
}

/**
 * Final part of program
 * User can save stack/queue, quit, or reuse the program
*/
void save_stack_country(StackCountry*& country) {
	char choice;
	std::cout << std::endl;
	std::cout << "Would you like to save your stack (Y/n):";
	if (choice == 'Y' || choice == 'y') {
		std::ofstream off_file;
		country->offload_data(off_file);
		country->delete_stack();
		delete country;
	}
	std::cout << std::endl;
	std::cout << "Would you like to re-run the program? (Y/n):";
	std::cin >> choice;
	if (choice == 'Y' || choice == 'y') {
		welcome_prompt();
	}
	else if (choice == 'N' || choice == 'n') {
		exit(0);
	}
}

/**
 * Final part of program
 * User can save stack/queue, quit, or reuse the program
*/

void save_queue_customer(QueueCustomer*& customer) {
	char choice;
	std::cout << std::endl;
	std::cout << "Would you like to save your stack (Y/n):";
	if (choice == 'Y' || choice == 'y') {
		std::ofstream off_file;
		customer->offload_data(off_file);
		customer->delete_queue();
		delete customer;
	}
	std::cout << std::endl;
	std::cout << "Would you like to re-run the program? (Y/n):";
	std::cin >> choice;
	if (choice == 'Y' || choice == 'y') {
		welcome_prompt();
	}
	else if (choice == 'N' || choice == 'n') {
		exit(0);
	}
}

/**
 * Final part of program
 * User can save stack/queue, quit, or reuse the program
*/
void save_queue_country(QueueCountry*& country) {
	char choice;
	std::cout << std::endl;
	std::cout << "Would you like to save your stack (Y/n):";
	if (choice == 'Y' || choice == 'y') {
		std::ofstream off_file;
		country->offload_data(off_file);
		country->delete_queue();
		delete country;
	}
	std::cout << std::endl;
	std::cout << "Would you like to re-run the program? (Y/n):";
	std::cin >> choice;
	if (choice == 'Y' || choice == 'y') {
		welcome_prompt();
	}
	else if (choice == 'N' || choice == 'n') {
		exit(0);
	}
}