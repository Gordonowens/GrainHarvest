// GrainHarvest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <string>
#include <fstream>
#include "Order.h"
#include "Business.h"

using std::cout; using std::cin;
using std::endl; using std::string;
using std::filesystem::directory_iterator;
using namespace std;

Order * GetOrders(string path, int number_files) {

    string temp_text;
    int order_numbers;
    int num_order = 0;
    int amount_order;
    string grain_type_order;
    static Order *orders;

    orders = new Order[number_files];

    for (const auto& file : directory_iterator(path)) {

        ifstream MyReadFile(file.path());
        
        //get order number
        getline(MyReadFile, temp_text);
        order_numbers = stoi(temp_text);

        //get order amount
        getline(MyReadFile, temp_text);
        amount_order = stoi(temp_text);

        //get order grain type 
        getline(MyReadFile, temp_text);
        grain_type_order = temp_text;

        //update order data
        orders[num_order].SetOrderData(order_numbers, amount_order, grain_type_order);

        //next order
        num_order += 1;
    }
    
    return orders; 
}

int GetNumFiles(string path) {

    int num_order = 0;

    for (const auto& file : directory_iterator(path)) {
      
        num_order += 1;
    }

    return num_order;
}

int main()
{
    //enter path to folder containing orders
    string path = "orders/";

    int number_files = GetNumFiles(path);
    //set up new busniess
    Business my_business = Business(number_files, GetOrders(path, number_files), number_files);

    cout << to_string(GetNumFiles(path));
    

    //my_business.PrintOrders();

	my_business.GetBestSelection();

    return EXIT_SUCCESS;
}
