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