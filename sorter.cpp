#include "sorter.h"

using namespace std::chrono;

/**
 * Copies one array to the other
*/
void copy_country_array(Country* arr_one, Country* arr_two, int index) {
    for (int i = 0; i < index; i++) {
        arr_one[i] = arr_two[i];
    }
}

/**
 * Copies one list ot the other
*/
void copy_country_list(CountryList*& list_one, CountryList*& list_two) {
    CountryNode* trav = list_two->first;
    while (trav != nullptr) {
        list_one->push_back_country(trav->data);
        trav = trav->next;
    }
}

/**
 * Copies one array to the other
*/
void copy_customer_array(Customer* arr_one, Customer* arr_two, int index) {
    for (int i = 0; i < index; i++) {
        arr_one[i] = arr_two[i];
    }
}

/**
 * Copies one list ot the other
*/
void copy_customer_list(CustomerList*& list_one, CustomerList*& list_two) {
    CustomerNode* trav = list_two->first;
    while (trav!= nullptr) {
        list_one->push_back_customer(trav->data);
        trav = trav->next;
    }
}

/**
 * Launches insertion sort algorithm for array, times average of 5 runs, an displays sorted times
*/
void launch_customer_insertionsort_array(Customer* arr, int size, char choice) {
    double time = 0.0;
    Customer *copy = new Customer[size]; //Creating copy of array to copy from after sorting
    copy_customer_array(copy, arr, size);
    for (int i = 0; i < 5; i++) {
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        customer_sort_array(arr,size,choice); //ARray gets sorted
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        time += duration_cast<duration<double>>(t2 - t1).count(); //Time gets added up for average
        if (i != 4) {
            copy_customer_array(arr,copy,size); //Array doesn't get updated the last iteration
            //this is to output data later
        }
    }

    delete[] copy; //deletes copy of array

    time = time / 5; //divides time by 5
    display_sorted_times(get_criteria_customer(choice),time, "Array"); //outputs times, displaydata.cpp
}

/**
 * Launches insertionsort for list
*/
void launch_customer_insertionsort_list(CustomerList*& list, char choice) {
    double time = 0.0;
    CustomerList* copy = new CustomerList; //Creates copy of list
    copy_customer_list(copy,list); //Copy gets objects from original ist
    for (int i = 0; i < 5; i++) {
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        customer_sort_list(list,choice); //List gets sorted
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        time += duration_cast<duration<double>>(t2 - t1).count(); //Time gets added up for averfage
        copy_customer_list(list,copy);// List gets copied all 5 iteratoins
    }

    //Decided list was useless to me after this
    //Outputting data from array was faster than iterating through an entire list
    copy->delete_list();
    list->delete_list();
    delete copy;
    delete list;
    time = time / 5; //Divides time by 5
    display_sorted_times(get_criteria_customer(choice), time, "List"); //outputs times, displaydata.cpp
}

/**
 * Launches insertion sort algorithm for array, times average of 5 runs, an displays sorted times
*/
void launch_country_insertionsort_array(Country* arr, int size, char choice) {
    double time = 0.0;
    Country *copy = new Country[size];
    copy_country_array(copy,arr,size);
    for (int i = 0; i < 5; i++) {
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        country_sort_array(arr, size, choice);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        time += duration_cast<duration<double>>(t2 - t1).count();
        if(i != 4) {
            copy_country_array(arr, copy, size);
        }
    }

    delete[] copy;
    time = time / 5;
    display_sorted_times(get_criteria_country(choice),time, "Array");
}

/**
 * Launches insertionsort for list
*/
void launch_country_insertionsort_list(CountryList*& list, char choice) {
    double time = 0.0;
    CountryList* copy = new CountryList;
    copy_country_list(copy, list);
    for (int i = 0; i < 5; i++) {
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        country_sort_list(list,choice);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        time += duration_cast<duration<double>>(t2 - t1).count();
        copy_country_list(list, copy);
    }
    copy->delete_list();
    list->delete_list();
    delete copy;
    delete list;
    time = time / 5;
    display_sorted_times(get_criteria_country(choice), time, "List");
}

/**
 * main big function that calls all the sorting algortithms
*/
void insertion_sort_country(Country* arr, int size, CountryList*& country, char choice) {
    display_time_borders();
    launch_country_insertionsort_list(country, choice);
    launch_country_insertionsort_array(arr, size, choice);
}

/**
 * main big function that calls all the sorting algortithms
*/
void insertion_sort_customer(Customer* arr, int size, CustomerList*& customer, char choice) {
    display_time_borders();
    launch_customer_insertionsort_list(customer,choice);
    launch_customer_insertionsort_array(arr,size,choice);
}