#ifndef LIST_H
#define LIST_H

#include <iostream>

#include "customer.h"
#include "country.h"
#include "node.h"

class List
{
public:
   /**
      Constructs an empty list.
   */
   List();
   /**
      Appends an element to the list.
      @param element the value to append
   */
   void push_back_country(Country newcountry);
   void push_back_customer(Customer newcustomer); 

private:
   Node* first;
   Node* last;
};

#endif