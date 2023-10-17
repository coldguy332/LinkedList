#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <sstream>
#include <fstream>

class Customer {
    public:
        Customer();
        Customer(std::string first_name, std::string last_name, int household_income, int credit_score, double total_sales);
        Customer(std::string first_name, std::string last_name, std::string customer_since);
        Customer(std::string first_name, std::string last_name, double total_sales);

        //Getters are first+last name, household_income,credit_score, total sales
        //We tryna chase that bread$$$$$$$
        //remove this when done plz

        std::string get_first_name() const;
        std::string get_last_name() const;
        int get_household_income() const;
        int get_credit_score() const;
        double get_total_sales() const;
        std::string get_customer_since() const;

        int get_serialized_date() const;
        
    private:
        std::string first_name;
        std::string last_name;
        int household_income;
        int credit_score;
        double total_sales;
        std::string customer_since;
};

#endif