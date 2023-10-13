#include "datainput.h"


void data_input_customer() {
    std::cout << "test" << std::endl;
    std::ifstream in_file;
    std::cout << "test" << std::endl;
    in_file.open("customersmall.csv");

    std::cout << "test" << std::endl;
    int index = line_counter(in_file);

    Customer arr[index];
    List customer;
    std::cout << "test" << std::endl;
    array_fill_customer(in_file,arr,index,customer);
    std::cout << "test" << std::endl;

    for (int i = 0; i < index; i++) {
        std::cout << arr[i].get_first_name() << " " << arr[i].get_total_sales() << std::endl;
    }
    
}

void choosing_dataset() {
    char choice;
    std::cout << "You have two datasets to choose from:" << std::endl;
    std::cout << "A) A dataset of customers who create sales for your (hypothetical) company" << std::endl;
    std::cout << "B) A dataset of countries who produce CO2 emissions to the earth" <<std::endl;
    std::cout << "What dataset would you like to choose:" ;
    std::cin >> choice;
    if (choice == 'A' || choice == 'a') {
        data_input_customer();
    }

}



int line_counter(std::ifstream& in_file) {
    //temp string for row of data to be stored in
	std::string temp_line;
	int index = 0; //Index that increments for every row counted

	getline(in_file, temp_line); //First row of csv file unnecessary, and therefore passed through

	while (!in_file.eof()) { //While loop functions until the end of the csv file
		getline(in_file,temp_line); //Cycles through the rows one by one
		index++; //index number increments
	}

	//Once the end of file is reached, program returns to the top of the page
	//NECESSARY or program will try reading from the bottom of the page when creating country arrays
	in_file.clear(); //Resets error flags on a stream such as EOF
	in_file.seekg(0);//sets position of next character to be read back to beginning of file

	return index; //Returns index number
}

void quoted_field(std::stringstream& ss, std::string& temp_string) {
    if (ss.peek() == '"') {  //program looks to see if quotation mark exists, doesn't actually "collect" it
		ss.ignore(); //If quote does exist, string stream will now pass over the first quote
		getline(ss,temp_string,'"'); //Reads until the next quotation mark
		ss.ignore(); //Final quote is ignored
	}
	else {
		getline(ss, temp_string, ','); //If no quotation marks, just parses regularly
	}
}


void array_fill_customer(std::ifstream& in_file, Customer *arr, int index, List customer) {
    std::string temp_line;
    std::string temp_data;

    std::string temp_first;
    std::string temp_last;
    std::string temp_houseincome;
    std::string temp_creditscore;
    std::string temp_totalsales;

    getline(in_file,temp_line);

    for (int i = 0; i < index; i++) {
        getline(in_file,temp_line);
        std::stringstream ss;
        ss.str(temp_line);

        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');

        getline(ss, temp_first, ',');
        getline(ss, temp_last, ',');

        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        quoted_field(ss,temp_data); //11
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');

        getline(ss, temp_houseincome, ',');
        getline(ss, temp_creditscore, ',');
        getline(ss, temp_totalsales);

        arr[i] = Customer(temp_first,temp_last, stoi(temp_houseincome), stoi(temp_creditscore), stod(temp_totalsales));
        customer.push_back_customer(Customer(temp_first,temp_last, stoi(temp_houseincome), stoi(temp_creditscore), stod(temp_totalsales)));
    }

    in_file.clear(); //Resets error flags on a stream such as EOF
	in_file.seekg(0);//sets position of next character to be read back to beginning of file
	

    in_file.close(); //Closes file
}