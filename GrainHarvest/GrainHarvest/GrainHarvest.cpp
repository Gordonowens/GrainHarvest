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


Order * GetOrders(string path) {

    string temp_text;
    int order_numbers;
    int num_order = 0;
    int amount_order;
    static Order orders[10];

    for (const auto& file : directory_iterator(path)) {

        ifstream MyReadFile(file.path());
        getline(MyReadFile, temp_text);
        order_numbers = stoi(temp_text);

        getline(MyReadFile, temp_text);
        amount_order = stoi(temp_text);

        getline(MyReadFile, temp_text);
        orders[num_order].SetOrderData(order_numbers, amount_order, temp_text);

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

    //set up new busniess
    Business my_business = Business(GetNumFiles(path), GetOrders(path));

    my_business.PrintOrders();

    return EXIT_SUCCESS;
}
