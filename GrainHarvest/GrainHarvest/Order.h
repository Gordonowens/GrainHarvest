#pragma once
#include <iostream>
#include <string>
#include "Order.h"

using std::cout; using std::cin;
using std::endl; using std::string;
using namespace std;

//represent a customer order
class Order {
private:
 
    int grain_value = 0;
    int order_number = 0;
    int grain_weight = 0;
   
public:

    void SetOrderData(int x, int y,  int p) {

        order_number = x;
        grain_value = y; 
        grain_weight = p;
    }

    int GetOrderNumber() {

        return order_number;
    }

    int GetOrderValue() {

        return grain_value;
    }

    int GetOrderWeight() {

        return grain_weight;
    }

    void PrintOrder() {
        cout << "order Number " << to_string(order_number) << " grain type "
            "order value " << to_string(grain_value);
    }
};

