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
		Country(std::string country_name, std::string code, int calling_code, int year ,
			long int emissions, long int population, int area, double percent, int density);

		std::string get_name() const;
		std::string get_code() const;
		int get_calling() const;
		int get_year() const;
		long int get_emissions() const;
		long int get_population() const;
		int get_area() const;
		double get_percent() const;
		int get_density() const;

		bool get_data_member(int choice);
		void offload_data(std::ofstream& off);

	private:
		std::string country_name; //'1'
		std::string code; //'2'
		int calling_code; //'3'
		int year; // '4'
		long int emissions; // '5'
		long int population; //6
		int area; //7
		double percent; //'8'
		int density; //'9'

};

/*
	output what criteria user wants to choose between 1 - 9


*/


#endif 

