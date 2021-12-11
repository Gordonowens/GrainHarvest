#pragma once

#include <iostream>
#include <string>
#include "Order.h"
#include <fstream>

using std::cout; using std::cin;
using std::endl; using std::string;
//using std::filesystem::directory_iterator;
using namespace std;

//Represent the grain silo company
//runs the logic of the grain business
//holds data relevant to running of grain business

struct solution {
    int number_elements;
    int* solution;
    int value;
    int time = 0;
};

class Business {
private:

    int number_order;
    int max_time = 50;
    Order *orders;
    solution schedule_solution;
    string out_put_folder;

public:

    Business(int y, Order* new_orders, int number_orders, string folder) {

        number_order = y;

        orders = new Order[number_orders];

        out_put_folder = folder;

        for (int i = 0; i < number_order; i++) {

            orders[i] = new_orders[i];
        }
    }

private:

    int GetNumberOrders() {

        return number_order;
    }

    /// <summary>
    /// outputs informationabout the solution to txt file of your choosing
    /// </summary>
    /// <param name="schedule_solution"></param>
    void OutPutSolution(struct solution schedule_solution) {

        ofstream myfile;
        myfile.open(out_put_folder);
        myfile << "Value: " + to_string(schedule_solution.value) + "\n";
        myfile << "Time: " + to_string(schedule_solution.time) + "\n";

        //iterate over solutions and print out the order number
        for (int i = 0; i < schedule_solution.number_elements; i++) {

            myfile << "Order: " + to_string(orders[schedule_solution.solution[i] - 1].GetOrderNumber()) + "\n";
        }

        myfile.close();
    }

    void PrintOrders() {

        for (int i = 0; i < number_order; i++) {

            orders[i].PrintOrder();
        }
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

        schedule.value = B[n][M];

        cout << "Selected Packs: ";

        while (n != 0) {
            if (B[n][M] != B[n - 1][M]) {
                cout << "\tPackage " << to_string(n) << " with W = " + to_string(W[n - 1]) << " and Value = " + to_string(V[n - 1]);
                schedule.time = schedule.time + W[n - 1];
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

public:
    void GetBestSelection() {
        //creates lists of order times and values
        //feeds them to knapsac algorithm
        //knapsac algorithm prints out result

        int* times = new int[number_order];
        int* values = new int[number_order];

        int* selection = new int[3];
        struct solution schedule_solution;

        for (int i = 0; i < number_order; i++) {
            times[i] = orders[i].GetOrderWeight();
        }

        for (int i = 0; i < number_order; i++) {
            values[i] = orders[i].GetOrderValue();
        }

        //pass order values and times to knapsac algorithm
        schedule_solution = knapsackDyProg(times, values, max_time, number_order);
        cout << "\n";

        OutPutSolution(schedule_solution);

    }

};
