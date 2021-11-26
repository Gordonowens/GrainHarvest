#pragma once
#include <iostream>
#include <string>
#include "Order.h"

using std::cout; using std::cin;
using std::endl; using std::string;

class Order {
public:
    int orderNumber = 0;
    string grainType = "no type";
    int grainAmount = 0;


    void setOrderValues(int x, int y, string z) {

        orderNumber = x;
        grainAmount = y;
        grainType = z;
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


};

