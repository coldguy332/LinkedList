#include "customer.h"

/**
 * Default constructur
*/
Customer::Customer() {
    this->first_name = "";
    this->last_name = "";
    this->household_income = 0;
    this->credit_score = 0;
    this->total_sales = 0.0;
    this->customer_since = "";
}

/**
 * Constructor for object when used in linked list and sorting
*/
Customer::Customer(std::string first_name, std::string last_name, int household_income, int credit_score, double total_sales) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->household_income = household_income;
    this->credit_score = credit_score;
    this->total_sales = total_sales;
    this->customer_since = "";
}

/**
 * Constructor for object when used in Stack
*/
Customer::Customer(std::string first_name, std::string last_name, std::string customer_since) { 
    this->first_name = first_name;
    this->last_name = last_name;
    this->household_income = 0;
    this->credit_score = 0;
    this->total_sales = 0.0;
    this->customer_since = customer_since;
}

/**
 * Constructor for object when used in a queue
*/
Customer::Customer(std::string first_name, std::string last_name, double total_sales) { //Queue
    this->first_name = first_name;
    this->last_name = last_name;
    this->household_income = 0;
    this->credit_score = 0;
    this->total_sales = total_sales;
    this->customer_since = "";
}

/**
 * Returns first name
*/
std::string Customer::get_first_name() const {
    return this->first_name;
}

/**
 * Returns last name
*/
std::string Customer::get_last_name() const{
    return this->last_name;
}

/**
 * Returns Household income
*/
int Customer::get_household_income() const{
    return this->household_income;
}

/**
 * Returns credit score
*/
int Customer::get_credit_score() const{
    return this->credit_score;
}

/**
 * Returns total sales (money customer spent on company)
*/
double Customer::get_total_sales() const{
    return this->total_sales;
}

/**
 * Returns date of when customer first used company
*/
std::string Customer::get_customer_since() const {
    return this->customer_since;
}

/**
 * IN part of later code, I used the date of when customer first used company
 * to compare to other customers to determine their loyalty
 * This function essentially converts the string date into an actual comparable number
*/
int Customer::get_serialized_date() const {
    std::stringstream ss;
    std::string temp_month;
    std::string temp_day;
    std::string temp_year;
    int month;
    int day;
    int year;
    int serial_result;
    ss.str(this->customer_since); //Will parse the date into separate strings
    getline(ss, temp_month, '/');
    getline(ss, temp_day, '/');
    getline(ss, temp_year);

    month = stoi(temp_month) * 100; //Factoring process
    day = stoi(temp_day) ;
    year = stoi(temp_year) * 10000;
    serial_result = year + month + day; 

    return serial_result; //Returns a serialized date
    
}

