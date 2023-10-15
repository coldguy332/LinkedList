#include "sorter.h"

using namespace std::chrono;

void copy_country_array(Country* arr_one, Country* arr_two, int index) {
    for (int i = 0; i < index; i++) {
        arr_one[i] = arr_two[i];
    }
}

void copy_country_list(CountryList& list_one, CountryList& list_two) {
    CountryNode* trav = list_two.first;
    while (trav != nullptr) {
        list_one.push_back_country(trav->data);
        trav = trav->next;
    }
}

void copy_customer_array(Customer* arr_one, Customer* arr_two, int index) {
    for (int i = 0; i < index; i++) {
        arr_one[i] = arr_two[i];
    }
}

void copy_customer_list(CustomerList& list_one, CustomerList& list_two) {
    CustomerNode* trav = list_two.first;
    while (trav!= nullptr) {
        list_one.push_back_customer(trav->data);
        trav = trav->next;
    }
}

void launch_customer_insertionsort_array(Customer* arr, int size, char choice) {
    double time = 0.0;
    Customer *copy = new Customer[size];
    copy_customer_array(copy, arr, size);
    for (int i = 0; i < 5; i++) {
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        customer_sort_array(arr,size,choice);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        time += duration_cast<duration<double>>(t2 - t1).count();
        if (i != 4) {
            copy_customer_array(arr,copy,size);
        }
    }

    delete[] copy;

    time = time / 5;
    display_sorted_times(get_criteria_customer(choice),time, "Array");
}

void launch_customer_insertionsort_list(CustomerList& list, char choice) {
    double time = 0.0;
    CustomerList copy;
    copy_customer_list(copy,list);
    for (int i = 0; i < 5; i++) {
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        customer_sort_list(list,choice);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        time += duration_cast<duration<double>>(t2 - t1).count();
        copy_customer_list(list,copy);
    }

    copy.delete_list();
    list.delete_list();
    time = time / 5;
    display_sorted_times(get_criteria_customer(choice), time, "List");
}

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

void launch_country_insertionsort_list(CountryList& list, char choice) {
    double time = 0.0;
    CountryList copy;
    copy_country_list(copy, list);
    for (int i = 0; i < 5; i++) {
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        country_sort_list(list,choice);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        time += duration_cast<duration<double>>(t2 - t1).count();
        copy_country_list(list, copy);
    }
    copy.delete_list();
    list.delete_list();
    time = time / 5;
    display_sorted_times(get_criteria_country(choice), time, "List");
}

void insertion_sort_country(Country* arr, int size, CountryList& country, char choice) {
    display_borders();
    launch_country_insertionsort_list(country, choice);
    launch_country_insertionsort_array(arr, size, choice);
}

void insertion_sort_customer(Customer* arr, int size, CustomerList& customer, char choice) {
    display_borders();
    launch_customer_insertionsort_list(customer,choice);
    launch_customer_insertionsort_array(arr,size,choice);
}