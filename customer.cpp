#include "customer.h"

Customer::Customer() {
    this->first_name = "";
    this->last_name = "";
    this->household_income = 0;
    this->credit_score = 0;
    this->total_sales = 0.0;
}

Customer::Customer(std::string first_name, std::string last_name, int household_income, int credit_score, double total_sales) {
    this->first_name = first_name;
    this->last_name = last_name;
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

