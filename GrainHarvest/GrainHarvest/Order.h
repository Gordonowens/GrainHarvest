#pragma once
#include <iostream>
#include <string>
#include "Order.h"

using std::cout; using std::cin;
using std::endl; using std::string;
using namespace std;

//represent a customer order
class Order {
public:
 
    int grain_amount = 0;
    int order_value = 0;
    int order_time = 0;
    int order_number = 0;

    string grain_type = "no type";
    
    void SetOrderData(int x, int y, string z) {

        order_number = x;
        grain_amount = y;
        grain_type = z;
    }

    void SetOrderValue(int value) {

        order_value = value;
    }

    void SetOrderTime(int value) {

        order_time = value;
    }

    int GetOrderNumber() {

        return order_number;
    }

    int GetOrderAmount() {

        return grain_amount;
    }

    int GetOrderTime() {

        return order_time;
    }

    int GetOrderValue() {

        return order_value;
    }

    string GetGrainType() {

        return grain_type;
    }

    void PrintOrder() {
        cout << "order Number " << to_string(order_number) << " grain type " << grain_type <<
            "order amount " << to_string(grain_amount) << "order value " << to_string(order_value) <<
            "order time " << to_string(order_time) << "\n";
    }
};

