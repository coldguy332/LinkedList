#ifndef QUEUECOUNTRY_H
#define QUEUECOUNTRY_H

#include <iostream>

#include "country.h"
#include "countrynode.h"

struct QueueCountry {

  QueueCountry();
  void push_back_in_order(Country data);
  void push_back(Country data);
  void pop_front();

  CountryNode* head;
  CountryNode* tail;  
};

#endif