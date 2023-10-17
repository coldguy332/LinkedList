#include "customer.h"

Customer::Customer() {
    this->first_name = "";
    this->last_name = "";
    this->household_income = 0;
    this->credit_score = 0;
    this->total_sales = 0.0;
    this->customer_since = "";
}

Customer::Customer(std::string first_name, std::string last_name, int household_income, int credit_score, double total_sales) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->household_income = household_income;
    this->credit_score = credit_score;
    this->total_sales = total_sales;
    this->customer_since = "";
}

Customer::Customer(std::string first_name, std::string last_name, std::string customer_since) { //Stack
    this->first_name = first_name;
    this->last_name = last_name;
    this->household_income = 0;
    this->credit_score = 0;
    this->total_sales = 0.0;
    this->customer_since = customer_since;
}
Customer::Customer(std::string first_name, std::string last_name, double total_sales) { //Queue
    this->first_name = first_name;
    this->last_name = last_name;
    this->household_income = 0;
    this->credit_score = 0;
    this->total_sales = total_sales;
    this->customer_since = "";
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

int Customer::get_serialized_date() const {
    std::stringstream ss;
    std::string temp_month;
    std::string temp_day;
    std::string temp_year;
    int month;
    int day;
    int year;
    int serial_result;
    ss.str(this->customer_since);
    getline(ss, temp_month, '/');
    getline(ss, temp_day, '/');
    getline(ss, temp_year);

    month = stoi(temp_month) * 100;
    day = stoi(temp_day) * 10;
    year = stoi(temp_year) * 1000;
    serial_result = year + month + day;

    return serial_result;

}

