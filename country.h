//
// Created by Amal Afsal for Sorting lab on 9/15/23.
//


#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include <fstream>


class Country {
	public:
		Country();
		Country(std::string country_name, long double emissions, long int population, int area);
		Country(int year, std::string country_name, long double emissions);

		std::string get_name() const;
		long double get_emissions() const;
		long int get_population() const;
		int get_area() const;
		int get_year() const;

		bool get_data_member(char criteria);

	private:
		std::string country_name; //'1'
		long double emissions; // '5'
		long int population; //6
		int area; //7
		int year;
};

/*
sort by emiisions population area, output name with whatever is sorted
*/

#endif 

