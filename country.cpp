#include "country.h"

/**
 * Default constructor for a country object
**/
Country::Country() {
	this->country_name = "";
	this->code = "";
	this->calling_code = 0;
	this->year = 0;
	this->emissions = 0;
	this->population = 0;
	this->area = 0;
	this->percent = 0.0;
	this->density = 0;
}

/**
 * Constructor for country object
 * will be utilized when parsing through csv file
 * @param all parameters will be stored as data members
**/
Country::Country(std::string country_name, std::string code, int calling_code, int year ,
	long int emissions, long int population, int area, double percent, int density) {
	this->country_name = country_name;
	this->code = code;
	this->calling_code = calling_code;
	this->year = year;
	this->emissions = emissions;
	this->population = population;
	this->area = area;
	this->percent = percent;
	this->density = density;
}

/**
 * returns country name
**/
std::string Country::get_name() const {
	return this->country_name;
}
/**
 * returns country code
**/
std::string Country::get_code() const {
	return this->code;
}
/**
 * returns country calling code
**/
int Country::get_calling() const {
	return this->calling_code;
}
/**
 * returns country year
**/
int Country::get_year() const {
	return this->year;
}
/**
 * returns country emissions
**/
long int Country::get_emissions() const {
	return this->emissions;
}
/**
 * returns country population
**/
long int Country::get_population() const {
	return this->population;
}
/**
 * returns country area
**/
int Country::get_area() const {
	return this->area;
}
/**
 * returns country percent
**/
double Country::get_percent() const {
	return this->percent;
}
/**
 * returns country density
**/
int Country::get_density() const {
	return this->density;
}

/**
 * Function that will be necessary in outputting data
 * In this program, -1 means an unknown as there is many missing values in csv
 * Program has to display first 50 items of sorted list
 * Top 50 will always be -1 as a result
 * this function will help mitigate the results (later explained in actual function)
 * @choice criteria to be sorted by
**/
bool Country::get_data_member(int choice){
	switch (choice) {
        case 1: 
            return this->get_name() == "-1";
        case 2:
            return this->get_code() == "-1";
        case 3:
            return this->get_calling() == -1;
        case 4:
            return this->get_year() == -1;
        case 5:
            return this->get_emissions() == -1;
        case 6:
            return this->get_population() == -1;
        case 7:
            return this->get_area()  == -1;
        case 8:
            return this->get_percent() == -1.0;
        case 9:
            return this->get_density()  == -1;
        default:
            return false;
    }
}

/**
 * helper function that will ouput data to a csv file
 * @param off ofstream that will output data
**/
void Country::offload_data(std::ofstream& off) {
	off << this->get_name() << "," << this->get_code() << "," << this->get_calling() << ","
	    << this->get_year() << "," << this->get_emissions() << "," << this->get_population() << ","
	    << this->get_area() << "," << this->get_percent() << "," << this->get_density();
}