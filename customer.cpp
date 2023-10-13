#include "customer.h"

Customer::Customer(std::string customer_id, std::string username, std::string first_name, std::string last_name, std::string street_address, std::string city,
                std::string state, int postal_code, std::string email_address, std::string gender, std::string company, std::string job_title,
                std::string customer_since, std::string social_security_number, std::string date_of_birth, int household_income, int credit_score,
                double total_sales) 
    {
        this->customer_id = customer_id;
        this->username = username;
        this->first_name = first_name;
        this->last_name = last_name;
        this->street_address = street_address;
        this->city = city;
        this->state = state;
        this->postal_code = postal_code;
        this->email_address = email_address;
        this->gender = gender;
        this->company = company;
        this->job_title = job_title;
        this->customer_since = customer_since;
        this->social_security_number = social_security_number;
        this->date_of_birth = date_of_birth;
        this->household_income = household_income;
        this->credit_score = credit_score;
        this->total_sales = total_sales;
}

std::string Customer::get_first_name() const {
    return this->first_name;
}
std::string Customer::get_last_name() const{
    return this->last_name;
}
int Customer::get_household_income() const{
    return this->household_income;
}
int Customer::get_credit_score() const{
    return this->credit_score;
}
double Customer::get_total_sales() const{
    return this->total_sales;
}

