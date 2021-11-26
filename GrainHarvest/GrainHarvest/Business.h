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
   
    string grainTypes[3] = { "Wheat", "Barley", "Canola" };
    int grainValue[3] = { 10, 15, 5 };
    int grainTime[3] = { 25, 30, 8 };

    //schedule represents 24 hours
    Order schedule[96];

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
            setOrderValueTime(i);

        }
    }

    void setOrderValueTime(int k) {

        for (int i = 0; i < sizeof(grainTypes) / sizeof(grainTypes[0]); i++) {

            if (orders[k].getGrainType() == grainTypes[i]) {
  
                orders[k].setOrderTime(grainTime[k] * orders[k].getOrderAmount());
                orders[k].setOrderValue(grainValue[k] * orders[k].getOrderAmount());
          
                break;
            }

        }

    }

    void printOrders() {

        for (int i = 0; i < numberOrder; i++) {

            orders[i].printOrder();
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
