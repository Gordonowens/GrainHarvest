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

struct solution {
    int number_elements;
    int* solution;
};
class Business {
public:

    int number_order;
    int grain_values[3] = { 150, 100, 50 };
    int max_time = 50;
    double grain_time[3] = { .25, .30, .17 };

    string grain_types[3] = { "A", "B", "C" };
    Order *orders;

    solution schedule_solution;

    Business(int y, Order* new_orders, int number_orders) {

        number_order = y;

        orders = new Order[number_orders];

        for (int i = 0; i < number_order; i++) {

            orders[i] = new_orders[i];
            SetOrderValueTime(i);
        }
    }

    int GetNumberOrders() {

        return number_order;
    }

    void SetOrders(Order* newOrders) {
        //input is a list of orders
        //iterates over the orders and adds then to the businesses list of orders

        
    }

    void SetOrderValueTime(int k) {
        //inputs: takes the index number of the orders array for order that needs
        // to calculate value and time

        //iterate over graint types
        
        for (int i = 0; i < sizeof(grain_types) / sizeof(grain_types[0]); i++) {


            

            //check if order has same grain type
            if (orders[k].GetGrainType() == grain_types[i]) {

                //update order value and time data
                //orders[k].SetOrderTime(round(grain_time[k] * orders[k].GetOrderAmount()));
                orders[k].SetOrderTime(orders[k].GetOrderWeight());
                orders[k].SetOrderValue(orders[k].GetOrderAmount());
                //orders[k].SetOrderValue(round(grain_values[k] * orders[k].GetOrderAmount()));
                break;
            }
            
        }
        
    }

    void GetBestSelection() {
        //creates lists of order times and values
        //feeds them to knapsac algorithm
        //knapsac algorithm prints out result

        int* times = new int[number_order];
        int* values = new int[number_order];

        int* selection = new int[3];
        struct solution schedule_solution;

        for (int i = 0; i < number_order; i++) {
            times[i] = orders[i].GetOrderTime();
        }

        for (int i = 0; i < number_order; i++) {
            values[i] = orders[i].GetOrderValue();
        }

        //pass order values and times to knapsac algorithm
        schedule_solution = knapsackDyProg(times, values, max_time, number_order);
        cout << "\n";

        for (int i = 0; i < schedule_solution.number_elements; i++) {

            cout << " " + to_string(orders[schedule_solution.solution[i] - 1].GetOrderNumber());
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
    
   
    double* ReturnGrainTime() {
        return grain_time;
    }

    void CreateOptimumSchedule() {

    }

    void CreateRandomSchedule() {

    }

    void PrintSchedule() {

    }

    int* resize(int* arr, int number_elements)
    {
        int* resize_arr = new int[number_elements + 1];
        for (int i = 0; i < number_elements; i++) {
            resize_arr[i] = arr[i];
        }

        return resize_arr;
    }

    struct solution knapsackDyProg(int* W, int* V, int M, int n) {

        int** B = new int* [n + 1];

        int selection_number = 1;
        int* selection_array = new int[selection_number];
        selection_array[0] = 0;

        struct solution schedule;
        

        for (int i = 0; i < (n + 1); i++) {
            B[i] = new int[M + 1];
        }

        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= M; j++) {

                B[i][j] = 0;
            }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= M; j++) {
                B[i][j] = B[i - 1][j];

                if ((j >= W[i - 1]) && (B[i][j] < B[i - 1][j - W[i - 1]] + V[i - 1])) {
                    B[i][j] = B[i - 1][j - W[i - 1]] + V[i - 1];
                }

                //cout << to_string(B[i][j]) << " ";
            }
            //cout << "\n";
        }

        cout << "Max Value:\t" << to_string(B[n][M]);

        cout << "Selected Packs: ";

        while (n != 0) {
            if (B[n][M] != B[n - 1][M]) {
                cout << "\tPackage " << to_string(n) << " with W = " + to_string(W[n - 1]) << " and Value = " + to_string(V[n - 1]);
                if (selection_array[0] != 0) {
                    selection_array = resize(selection_array, selection_number);
                    selection_array[selection_number] = n;

                    selection_number++;
                }
                else {
                    selection_array[selection_number - 1] = n;
                    
                    
                }
                M = M - W[n - 1];
            }

            n--;
        }

        schedule.number_elements = selection_number;
        schedule.solution = selection_array;

        return schedule;
    }
};
