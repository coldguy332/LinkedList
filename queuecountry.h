#ifndef QUEUECOUNTRY_H
#define QUEUECOUNTRY_H

#include <iostream>
#include <iomanip>
#include <fstream>

#include "country.h"
#include "countrynode.h"

//rank emissions and fine countries >:)
struct QueueCountry {

  QueueCountry();
  void push_back_in_order(Country data);
  void push_back(Country data);
  void pop_front();
  void print();

  void delete_queue();

  void offload_data(std::ofstream& off);

  CountryNode* head;
  CountryNode* tail;  
};

#endif