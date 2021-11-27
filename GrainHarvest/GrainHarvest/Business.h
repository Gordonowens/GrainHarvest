#pragma once

#include <iostream>
#include <string>
#include "Order.h"

using std::cout; using std::cin;
using std::endl; using std::string;
using namespace std;

//Represent the grain silo company
//runs the logic of the grain business
//holds data relevant to running of grain business
class Business {
public:

    int number_order;
    string grain_types[3] = { "Wheat", "Barley", "Canola" };
    int grain_values[3] = { 60, 100, 120 };
    int grain_time[3] = { 10, 20, 30 };
    Order orders[10];
    //schedule represents 24 hours
    Order schedule[96];

    Business(int y, Order* new_orders) {

        number_order = y;

        SetOrders(new_orders);
    }

    int GetNumberOrders() {

        return number_order;
    }

    void SetOrders(Order* newOrders) {
        //input is a list of orders
        //iterates over the orders and adds then to the businesses list of orders

        for (int i = 0; i < number_order; i++) {

            orders[i] = newOrders[i];
            SetOrderValueTime(i);

        }
    }

    void SetOrderValueTime(int k) {
        //inputs: takes the index number of the orders array for order that needs
        // to calculate value and time

        //iterate over graint types
        for (int i = 0; i < sizeof(grain_types) / sizeof(grain_types[0]); i++) {

            //check if order has same grain type
            if (orders[k].GetGrainType() == grain_types[i]) {

                //update order value and time data
                orders[k].SetOrderTime(grain_time[k] * orders[k].GetOrderAmount());
                orders[k].SetOrderValue(grain_values[k] * orders[k].GetOrderAmount());

                break;
            }
        }
    }

    void PrintOrders() {

        for (int i = 0; i < number_order; i++) {

            orders[i].PrintOrder();
        }
    }

    void UpdateSchedule() {

    }

    bool CheckSchedule() {
        return true;
    }

    int ReturnScheduleValue() {

        return 5;
    }

    int* ReturnGrainValues() {

        return grain_values;
    }
    
   
    int* ReturnGrainTime() {
        return grain_time;
    }

    void CreateOptimumSchedule() {

    }

    void CreateRandomSchedule() {

    }

    void PrintSchedule() {

    }
};
