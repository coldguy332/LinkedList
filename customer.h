#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <fstream>

class Customer {
    public:
        Customer(std::string customer_id, std::string username, std::string first_name, std::string street_address, std::string city,
                std::string state, int postal_code, std::string email_address, std::string gender, std::string company, std::string job_title,
                std::string customer_since, std::string social_security_number, std::string date_of_birth, int household_income, int credit_score,
                double total_sales);

        //Getters are first+last name, household_income,credit_score, total sales
        //We tryna chase that bread$$$$$$$
        //remove this when done plz

        
    private:
        std::string customer_id;
        std::string username;
        std::string first_name;
        std::string street_address;
        std::string city;
        std::string state;
        int postal_code;
        std::string email_address;
        std::string gender;
        std::string company;
        std::string job_title;
        std::string customer_since;
        std::string social_security_number;
        std::string date_of_birth;
        int household_income;
        int credit_score;
        double total_sales;
};

#endif