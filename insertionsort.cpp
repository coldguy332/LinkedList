#include <iostream>

#include "insertionsort.h"

/**
 * boolean that is essentially comparison for insertion sort 
 * in this case this is for the array portion
*/
bool customer_criteria_array(Customer* arr, Customer next, int index, char choice) {
    switch(choice) {
        case 'A' :
            return arr[index - 1].get_household_income() > next.get_household_income();
        case 'B':
            return arr[index - 1].get_credit_score() > next.get_credit_score();
        case 'C':
            return arr[index - 1].get_total_sales() > next.get_total_sales();
        default:
            return false;
    }
}

/**
 * boolean that is essentially comparison for insertion sort 
 * in this case this is for the array portion
*/
bool country_criteria_array(Country* arr, Country next, int index, char choice) {
    switch(choice) {
        case 'A':
            return arr[index - 1].get_emissions() > next.get_emissions();
        case 'B':
            return arr[index - 1].get_population() > next.get_population();
        case 'C':
            return arr[index - 1].get_area() > next.get_area();
        default:
            return false;
    }
}

/**
 * Helper function for function that inserts a node into linked list
 * checks if the head's data member is greater or equal to new node's data member
*/
bool customer_head_ptr_check(CustomerNode* head,CustomerNode* new_node, char choice) {
    switch(choice) {
        case 'A' :
            return head->data.get_household_income() >= new_node->data.get_household_income();
        case 'B':
            return head->data.get_credit_score() >= new_node->data.get_credit_score();
        case 'C':
            return head->data.get_total_sales() >= new_node->data.get_total_sales();
        default:
            return false;
    }
}

/**
 * Helper function for function that inserts a node into linked list
 * checks if the current next ptr is less than new node's data member
*/
bool customer_curr_ptr_check(CustomerNode* curr,CustomerNode* new_node, char choice) {
    switch(choice) {
        case 'A' :
            return curr->next->data.get_household_income() < new_node->data.get_household_income();
        case 'B':
            return curr->next->data.get_credit_score() < new_node->data.get_credit_score();
        case 'C':
            return curr->next->data.get_total_sales() < new_node->data.get_total_sales();
        default:
            return false;
    }
}

/**
 * Helper function for function that inserts a node into linked list
 * checks if the head's data member is greater or equal to new node's data member
*/
bool country_head_ptr_check(CountryNode*head, CountryNode* new_node, char choice) {
    switch(choice) {
        case 'A':
            return head->data.get_emissions() >= new_node->data.get_emissions();
        case 'B':
            return head->data.get_population() >= new_node->data.get_population();
        case 'C':
            return head->data.get_area() >= new_node->data.get_area();
        default:
            return false;
    }
}

/**
 * Helper function for function that inserts a node into linked list
 * checks if the current next ptr is less than new node's data member
*/
bool country_curr_ptr_check(CountryNode*curr, CountryNode* new_node, char choice) {
    switch(choice) {
        case 'A':
            return curr->next->data.get_emissions() < new_node->data.get_emissions();
        case 'B':
            return curr->next->data.get_population() < new_node->data.get_population();
        case 'C':
            return curr->next->data.get_area() < new_node->data.get_area();
        default:
            return false;
    }
}

/**
 * Inserts a node into a sorted linked list
 * @https://www.geeksforgeeks.org/cpp-program-for-insertion-sort-in-a-singly-linked-list/#
*/
void sorted_insert_customer(CustomerNode*& headref, CustomerNode* new_node, char choice) {
    //If sorted list hasn't been created yet, newnode becomes new head of sorted list 
    //or if the head has a greater value than the newnode, the newnode is the new head
    if (headref == nullptr || customer_head_ptr_check(headref,new_node,choice)) { 
        new_node->next = headref;
        headref = new_node;
    }
    else {
        CustomerNode* current = headref;
        //Current set to the headref and iterates to the end of sorted list and checks if 
        //current->next is less than the newnode
        while (current->next != nullptr && customer_curr_ptr_check(current,new_node,choice)) {
            current = current->next;
        }
        //Newnode becomes the end of the sorted list
        new_node->next = current->next;
        //Previous end of list points to the new node
        current->next = new_node;
    }
}

/**
 * MAIN INSERTION SORT FUNCTION FOR LISTS
 * @https://www.geeksforgeeks.org/cpp-program-for-insertion-sort-in-a-singly-linked-list/#
*/
void customer_sort_list(CustomerList*& customer, char choice) {
    CustomerNode* sorted = nullptr; //Sorted is the head for the sorted lists
    CustomerNode* curr = customer->first; //Iterator starts at lists head ptr;
    while (curr != nullptr) { //Iterates until end of list , essentially the unsorted list
        CustomerNode* next = curr->next; //Saves position of next ptr of current
        sorted_insert_customer(sorted,curr,choice); //PLugs in curr into function that inserts nodes into sorted list
        curr = next; //Curr is now equal to its original next position
    }
    customer->first = sorted; //Once list has been sorted, customer head ptr now said to sorted.
}

/**
 * Inserts a node into a sorted linked list
 * Helper function
 * @https://www.geeksforgeeks.org/cpp-program-for-insertion-sort-in-a-singly-linked-list/#
*/
void sorted_insert_country(CountryNode *&headref, CountryNode* new_node, char choice) {
    //If sorted list hasn't been created yet, newnode becomes new head of sorted list 
    //or if the head has a greater value than the newnode, making the newnode the new head
    if (headref == nullptr || country_head_ptr_check(headref, new_node, choice)) {
        new_node->next = headref;
        headref = new_node;
    }
    else {
        CountryNode* current = headref;
        //Current set to the headref and iterates to the end of sorted list and checks if 
        //current->next is less than the newnode
        while (current->next != nullptr && country_curr_ptr_check(current,new_node,choice)) {
            current = current->next;
        }
        //Newnode becomes the end of the sorted list
        new_node->next = current->next;
        //Previous end of list points to the new node
        current->next = new_node; 
    }
}

/**
 * MAIN INSERTION SORT FUNCTION FOR LISTS
 * @https://www.geeksforgeeks.org/cpp-program-for-insertion-sort-in-a-singly-linked-list/#
*/
void country_sort_list(CountryList*& country, char choice) {
    CountryNode* sorted = nullptr; //Sorted is the head for the sorted lists
    CountryNode* curr = country->first; //Iterator starts at lists head ptr;
    while (curr != nullptr) { //Iterates until end of list , essentially the unsorted list
        CountryNode* next = curr->next; //Saves position of next ptr of current
        sorted_insert_country(sorted,curr,choice); //PLugs in curr into function that inserts nodes into sorted list
        curr = next; //Curr is now equal to its original next position
    }
    country->first = sorted; //Once list has been sorted, customer head ptr now said to sorted.
} 




/**
 * Sorts array by basic insertion sort algorithm (yawn)
 * citing zybooks
*/
void customer_sort_array(Customer* arr, int index, char choice) {
    for (int i = 1; i < index; i++) {
        Customer next = arr[i];
        int j = i;       //Function that compares criteria
        while (j > 0 && customer_criteria_array(arr, next, j, choice)) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = next;
    }
}

/**
 * Sorts array by basic insertion sort algorithm (yawn)
 * citing zybooks
*/
void country_sort_array(Country* arr, int index, char choice) {
    for (int i = 1; i < index; i++) {
        Country next = arr[i];
        int j = i;       //Function that compares criteria
        while (j > 0 && country_criteria_array(arr, next, j, choice)) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = next;
    }
}

