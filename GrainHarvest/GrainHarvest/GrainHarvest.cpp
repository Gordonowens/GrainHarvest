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






Order * getOrders(string path) {

    string myText;
    int orderNumber;
    int numOrder = 0;
    int amountOrder;
    static Order orders[10];

    for (const auto& file : directory_iterator(path)) {
        ifstream MyReadFile(file.path());
        getline(MyReadFile, myText);
        orderNumber = stoi(myText);

        getline(MyReadFile, myText);
        amountOrder = stoi(myText);

        getline(MyReadFile, myText);
        orders[numOrder].setOrderValues(orderNumber, amountOrder, myText);

        numOrder += 1;
    }
    
    return orders; 
}

int getNumFiles(string path) {

    int numOrder = 0;

    for (const auto& file : directory_iterator(path)) {
      
        numOrder += 1;
    }

    return numOrder;
}

int main()
{
    string path = "orders/";

    Business myBusiness = Business(getNumFiles(path), getOrders(path));

    myBusiness.printOrders();

    return EXIT_SUCCESS;
}
