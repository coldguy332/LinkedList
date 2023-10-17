#include "datainput.h"

/**
 * Function that starts the data input process for customer dataset
 * Array and linked list created and filled with customer objects
*/
void data_input_customer() {
    
    std::ifstream in_file;
    in_file.open("customer.csv");
    int index = line_counter(in_file); //Counts how many lines are in csv file

    Customer *arr = new Customer[index]; //Creating new customer array
    CustomerList* customer = new CustomerList; //Creating new customer list

    array_list_fill_customer(in_file, arr, index, customer);
    choose_criteria_customer(arr,customer,index); //Goes back to function from prompt.cpp to choose what to sort by
    
}

/**
 * Function that starts the data input process for country dataset
 * Array and linked list created and filled with country objects
*/
void data_input_country() {
    std::ifstream in_file;
    in_file.open("countries.csv");
    int index = line_counter(in_file); //Counts how many lines are in csv file

    Country *arr= new Country[index]; //Creating new country array
    CountryList* country = new CountryList; //Creating new country list

    array_list_fill_country(in_file,arr,index,country);
    choose_criteria_country(arr, country, index); //Goes back to function from prompt.cpp to choose what to sort by
}



/**
 * Counts and retunrs the amount of lines that are in csv file
*/
int line_counter(std::ifstream& in_file) {
    //temp string for row of data to be stored in
	std::string temp_line;
	int index = 0; //Index that increments for every row counted

	getline(in_file, temp_line); //First row of csv file unnecessary, and therefore passed through

	while (getline(in_file, temp_line)) { //While loop functions until the end of the csv file
		index++; //index number increments
	}

	//Once the end of file is reached, program returns to the top of the page
	//NECESSARY or program will try reading from the bottom of the page when creating country arrays
	in_file.clear(); //Resets error flags on a stream such as EOF
	in_file.seekg(0);//sets position of next character to be read back to beginning of file

	return index; //Returns index number
}

/**
 * Function that parses through data values that have quotation marks
 * @param ss stringstream passed by reference
 * @param temp_string string that will store data value passed by reference
*/
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

/**
 * This function checks if the temp_density that was parsed through is an empty string or not
 * Issue: Windows and Linux has differences in reading CSV files
 * Ideally this code would work on windows without this function but not on linux
 * Without this function on linux, temp_density looks like an empty string even though it's not (returns a carriage return on linux)
 * @param density //Passing by reference of temp_density
 * @https://stackoverflow.com/questions/4081750/difference-in-reading-csv-file-in-unix-system-windows-system
**/
void density_check(std::string& density){
	std::stringstream dens(density); //Sets stringstream to the temp_density string
	density = ""; //Sets temp_destiny string to an empty string
	dens >> density; //Density stores whatever was in stringstream
	/*Originally, temp_density had a value of a carriage return if there was no value
	As a result, it showed up blank but wasnt "empty"
	Now if there was any value in the temp_density before the final result would be
	temp_density += ""
	So now, temp_density will either show up as a value or an actual empty string
	*/ 
}


/**
 * Converts any empty strings into "-1" which symbolizes an unknown
**/
void unknown_checker(std::string& emissions, std::string& population, std::string& area) {
    if (emissions.empty()) {
		emissions = "-1.0";
	}
	if (population.empty()) {
		population = "-1" ;
	}
	if (area.empty()) {
		area = "-1";
	}
}


/**
 * Fills both array and list with customer objects
*/
void array_list_fill_customer(std::ifstream& in_file, Customer *arr, int index, CustomerList*& customer) {
    std::string temp_line; //Temp line to store entire getline into
    std::string temp_data; //Data members that we are skipping over

    std::string temp_first; //Temp data member strings that we need
    std::string temp_last;
    std::string temp_houseincome;
    std::string temp_creditscore;
    std::string temp_totalsales;

    getline(in_file,temp_line); //First line describes csv, needs to be skipped over

    for (int i = 0; i < index; i++) {
        getline(in_file,temp_line);
        std::stringstream ss;
        ss.str(temp_line); //Stringstream takes in the line of csv

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

        //New list and array formed from the paramaters collected above
        arr[i] = Customer(temp_first,temp_last, stoi(temp_houseincome), stoi(temp_creditscore), stod(temp_totalsales)); 
        customer->push_back_customer(Customer(temp_first,temp_last, stoi(temp_houseincome), stoi(temp_creditscore), stod(temp_totalsales)));
    }
    in_file.clear(); //Resets error flags on a stream such as EOF
	in_file.seekg(0);//sets position of next character to be read back to beginning of file
	
    in_file.close(); //Closes file
}

/**
 * Fills both array and list with country objects
*/
void array_list_fill_country(std::ifstream& in_file, Country* arr, int index, CountryList*& customer) {
    std::string temp_line; //Temp line to store entire getline into
    std::string temp_data; //Data members that we are skipping over

    std::string temp_countryname; //Temp data member strings that we need
    std::string temp_emissions;
    std::string temp_population;
    std::string temp_area;

    getline(in_file, temp_line);  //First line describes csv, needs to be skipped over
    for (int i = 0; i < index; i++) {
        getline(in_file,temp_line);
        std::stringstream ss;
        ss.str(temp_line); //Stringstream takes in the line of csv

        getline(ss, temp_countryname, ',');
        getline(ss, temp_data, ',');
        quoted_field(ss, temp_data); //Parses through quoted field
        getline(ss, temp_data, ',');
        getline(ss, temp_emissions, ',');
        getline(ss, temp_population, ',');
        getline(ss, temp_area, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data);
        density_check(temp_data); //Converts density to -1 if empty

        //Converts any unknowns into -1
        unknown_checker(temp_emissions,temp_population,temp_area);

        //New list and array formed from the paramaters collected above
        arr[i] = Country(temp_countryname, stold(temp_emissions), stol(temp_population), stoi(temp_area));
        customer->push_back_country(Country(temp_countryname, stol(temp_emissions), stol(temp_population), stoi(temp_area)));
    }
    in_file.clear(); //Resets error flags on a stream such as EOF
	in_file.seekg(0);//sets position of next character to be read back to beginning of file
	
    in_file.close(); //Closes file
}


/**
 * Fills a stack with customers or countries
*/
void stack_fill(char choice) {
    if (choice == 'A') {
        StackCustomer* customer = new StackCustomer; //New stack created
        std::ifstream in_file;
        in_file.open("customer.csv");
        stack_fill_customer(customer, in_file); //Stack filled with customers
        customer_stack_interaction(customer); //Function called from prompt.cpp
    }
    if (choice == 'B') {
        StackCountry* country = new StackCountry; //New stack created
        std::ifstream in_file;
        in_file.open("countries.csv");
        stack_fill_country(country, in_file); //Stack filled with countries
        country_stack_interaction(country); //Function called from prompt.cpp
    }
}

/**
 * Program parses through csv to create stack of objects
 * Mostly same from linked list and array functions
*/
void stack_fill_customer(StackCustomer*& customer, std::ifstream& in_file) {
    std::string temp_line, temp_data; //templine stores getline, tempdata stores "useless information"

    std::string temp_first_name; //Paramaters that will be passed into customer constructor
    std::string temp_last_name;
    std::string temp_customer_since;

    int index = line_counter(in_file);

    getline(in_file,temp_line); 

    for (int i = 0; i < index; i++) {
        getline(in_file,temp_line);
        std::stringstream ss;
        ss.str(temp_line);

        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');

        getline(ss, temp_first_name, ',');
        getline(ss, temp_last_name, ',');

        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        quoted_field(ss,temp_data); 
        getline(ss, temp_data, ',');
        getline(ss, temp_customer_since, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');

        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data);

        //Objects are pushed in a sortable order
        customer->push_in_order(Customer(temp_first_name,temp_last_name,temp_customer_since));
    }
    in_file.clear(); //Resets error flags on a stream such as EOF
	in_file.seekg(0);//sets position of next character to be read back to beginning of file
	
    in_file.close(); //Closes file
}

/**
 * Program parses through csv to create stack of objects
 * Mostly same from linked list and array functions
*/
void stack_fill_country(StackCountry*& country, std::ifstream& in_file) {
    std::string temp_line, temp_data; //templine stores getline, tempdata stores "useless information"
   
    std::string temp_year; //Paramaters that will be passed into customer constructor
    std::string temp_country_name;
    std::string temp_emissions;

    int index = line_counter(in_file);

    getline(in_file,temp_line); 

    for (int i = 0; i < index; i++) {
        getline(in_file,temp_line);
        std::stringstream ss;
        ss.str(temp_line);

        getline(ss, temp_country_name, ',');
        getline(ss, temp_data, ',');
        quoted_field(ss, temp_data);
        getline(ss, temp_year, ',');
        getline(ss, temp_emissions, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data);
        density_check(temp_data);

        country->push_in_order(Country(stoi(temp_year),temp_country_name,stold(temp_emissions)));
    }
    in_file.clear(); //Resets error flags on a stream such as EOF
	in_file.seekg(0);//sets position of next character to be read back to beginning of file
	
    in_file.close(); //Closes file
}

/**
 * Fills queues with either customer or country objects
*/
void queue_fill(char choice) {
    if (choice == 'A') {
        QueueCustomer* customer = new QueueCustomer; //New customer queue created
        std::ifstream in_file;
        in_file.open("customer.csv");
        queue_fill_customer(customer, in_file); //Customer queue filled with objects
        customer_queue_interaction(customer); //Function called from prompt.cpp
    }
    if (choice == 'B') {
        QueueCountry* country = new QueueCountry; //New contry queue created
        std::ifstream in_file;
        in_file.open("countries.csv");
        queue_fill_country(country, in_file); //Country queue filled with objects
        country_queue_interaction(country); //Function called from prompt.cpp
    }
}

/**
 * Fills queue with customers
*/
void queue_fill_customer(QueueCustomer*& customer, std::ifstream& in_file) {
    std::string temp_line, temp_data;

    std::string temp_first_name;
    std::string temp_last_name;
    std::string temp_total_sales;

    int index = line_counter(in_file);

    getline(in_file,temp_line); 

    for (int i = 0; i < index; i++) {
        getline(in_file,temp_line);
        std::stringstream ss;
        ss.str(temp_line);

        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');

        getline(ss, temp_first_name, ',');
        getline(ss, temp_last_name, ',');

        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        quoted_field(ss,temp_data); 
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');

        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_total_sales);

        customer->push_back_in_order(Customer(temp_first_name,temp_last_name,stod(temp_total_sales)));

    }
    in_file.clear(); //Resets error flags on a stream such as EOF
	in_file.seekg(0);//sets position of next character to be read back to beginning of file
	
    in_file.close(); //Closes file
}

/**
 * Fills queue with countries
*/
void queue_fill_country(QueueCountry*& country, std::ifstream& in_file) {
    std::string temp_line, temp_data;
    std::string temp_year;
    std::string temp_country_name;
    std::string temp_emissions;

    int index = line_counter(in_file);

    getline(in_file,temp_line); 

    for (int i = 0; i < index; i++) {
        getline(in_file,temp_line);
        std::stringstream ss;
        ss.str(temp_line);

        getline(ss, temp_country_name, ',');
        getline(ss, temp_data, ',');
        quoted_field(ss, temp_data);
        getline(ss, temp_year, ',');
        getline(ss, temp_emissions, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data, ',');
        getline(ss, temp_data);
        density_check(temp_data);

        country->push_back_in_order(Country(stoi(temp_year),temp_country_name,stold(temp_emissions)));
    }
    in_file.clear(); //Resets error flags on a stream such as EOF
	in_file.seekg(0);//sets position of next character to be read back to beginning of file
	
    in_file.close(); //Closes file
}