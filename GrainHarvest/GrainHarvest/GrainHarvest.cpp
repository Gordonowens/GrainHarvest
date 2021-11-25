// GrainHarvest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <string>
#include <fstream>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::filesystem::directory_iterator;
using namespace std;


class Order {
public:
    string orderName;

    Order(string x = "blank order") {
        orderName = x;
    }

    string getName() {

        return orderName;
    }

};

class Business {
public:

    int numberOrder;
    Order orders[10];

    Business(int y, Order* newOrders) {
        
        numberOrder = y;

        setOrders(newOrders);   
    }

    int getNumberOrders(){

        return numberOrder;
    }

    void setOrders (Order * newOrders) {

        for (int i = 0; i < numberOrder; i++) {

            orders[i] = newOrders[i];

        }
    }

    void printOrders() {

        for (int i = 0; i < numberOrder; i++) {

            cout << orders[i].getName() << "\n";
        }
    }
};


Order * getOrders(string path) {

    string myText;
    int numOrder = 0;
    static Order orders[10];

    for (const auto& file : directory_iterator(path)) {
        ifstream MyReadFile(file.path());
        getline(MyReadFile, myText);
        
        orders[numOrder] = Order(myText);
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
