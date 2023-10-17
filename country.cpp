#include "country.h"

/**
 * Default constructor for a country object
**/
Country::Country() {
	this->country_name = "";
	this->emissions = 0.0;
	this->population = 0;
	this->area = 0;
	this->year = 0;
}

/**
 * Constructor for country object
 * will be utilized when parsing through csv file
 * @param all parameters will be stored as data members
**/
Country::Country(std::string country_name, long double emissions, long int population, int area) {
	this->country_name = country_name;
	this->emissions = emissions;
	this->population = population;
	this->area = area;
	this->year = 0;
}

Country::Country(int year, std::string country_name, long double emissions) {
	this->country_name = country_name;
	this->emissions = emissions;
	this->population = 0;
	this->area = 0;
	this->year = year;
}

/**
 * returns country name
**/
std::string Country::get_name() const {
	return this->country_name;
}

long double Country::get_emissions() const {
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

int Country::get_year() const {
	return this->year;
}

/**
 * Function that will be necessary in outputting data
 * In this program, -1 means an unknown as there is many missing values in csv
 * Program has to display first 50 items of sorted list
 * Top 50 will always be -1 as a result
 * this function will help mitigate the results (later explained in actual function)
 * @choice criteria to be sorted by
**/
bool Country::get_data_member(char criteria){
	switch (criteria) {
        case 'A':
            return this->get_emissions() == -1.0;
        case 'B':
            return this->get_population() == -1;
        case 'C':
            return this->get_area()  == -1;
        default:
            return false;
    }
}
