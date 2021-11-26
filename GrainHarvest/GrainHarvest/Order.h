#pragma once
#include <iostream>
#include <string>
#include "Order.h"

using std::cout; using std::cin;
using std::endl; using std::string;
using namespace std;


class Order {
public:
    int orderNumber = 0;
    string grainType = "no type";
    int grainAmount = 0;
    int orderValue = 0;
    int orderTime = 0;

    void setOrderValues(int x, int y, string z) {

        orderNumber = x;
        grainAmount = y;
        grainType = z;
    }

    void setOrderValue(int value) {

        orderValue = value;
    }

    void setOrderTime(int value) {

        orderTime = value;
    }

    int getOrderNumber() {

        return orderNumber;
    }

    int getOrderAmount() {

        return grainAmount;
    }

    string getGrainType() {

        return grainType;
    }

    void printOrder() {
        cout << "order Number " << to_string(orderNumber) << " grain type " << grainType <<
            "order amount " << to_string(grainAmount) << "order value " << to_string(orderValue) <<
            "order time " << to_string(orderTime) << "\n";
    }


};

