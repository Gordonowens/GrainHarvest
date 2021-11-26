#pragma once

#include <iostream>
#include <string>
#include "Order.h"

using std::cout; using std::cin;
using std::endl; using std::string;
using namespace std;

class Business {
public:

    int numberOrder;
    Order orders[10];
    Order schedule[5];

    Business(int y, Order* newOrders) {

        numberOrder = y;

        setOrders(newOrders);
    }

    int getNumberOrders() {

        return numberOrder;
    }

    void setOrders(Order* newOrders) {

        for (int i = 0; i < numberOrder; i++) {

            orders[i] = newOrders[i];

        }
    }

    void printOrders() {

        for (int i = 0; i < numberOrder; i++) {

            cout << "order Number " << to_string(orders[i].getOrderNumber()) << " grain type " << orders[i].getGrainType() <<
                "order amount " << to_string(orders[i].getOrderAmount()) << "\n";
        }
    }

    void updateSchedule() {

    }

    bool checkSchedule() {
        return true;
    }

    int returnScheduleValue() {

        return 5;
    }

    void createOptimumSchedule() {

    }

    void createRandomSchedule() {

    }

    void printSchedule() {

    }
};
