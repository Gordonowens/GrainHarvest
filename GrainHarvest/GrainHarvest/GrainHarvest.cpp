// GrainHarvest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <string>
#include <fstream>
#include "Order.h"
#include "Business.h"

using std::cout; using std::cin;
using std::endl; using std::string;
using std::filesystem::directory_iterator;
using namespace std;

void knapsackDyProg(int* W, int* V, int M, int n) {


    int** B = new int* [n + 1];

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
             
			cout << to_string(B[i][j]) << " ";
		}
		cout << "\n";
	}

	cout << "Max Value:\t" <<  to_string(B[n][M]);

	cout << "Selected Packs: ";

	while (n != 0) {
		if (B[n][M] != B[n - 1][M]) {
			cout << "\tPackage " <<  to_string(n) <<  " with W = " + to_string(W[n - 1]) << " and Value = " + to_string(V[n - 1]);

			M = M - W[n - 1];
		}

		n--;
	}
}

Order * GetOrders(string path) {

    string temp_text;
    int order_numbers;
    int num_order = 0;
    int amount_order;
    static Order orders[10];

    for (const auto& file : directory_iterator(path)) {

        ifstream MyReadFile(file.path());
        getline(MyReadFile, temp_text);
        order_numbers = stoi(temp_text);

        getline(MyReadFile, temp_text);
        amount_order = stoi(temp_text);

        getline(MyReadFile, temp_text);
        orders[num_order].SetOrderData(order_numbers, amount_order, temp_text);

        num_order += 1;
    }
    
    return orders; 
}

int GetNumFiles(string path) {

    int num_order = 0;

    for (const auto& file : directory_iterator(path)) {
      
        num_order += 1;
    }

    return num_order;
}

int main()
{
    //enter path to folder containing orders
    string path = "orders/";

    //set up new busniess
    Business my_business = Business(GetNumFiles(path), GetOrders(path));

    cout << to_string(GetNumFiles(path));
    

    //my_business.PrintOrders();

	my_business.GetBestSelection();

    return EXIT_SUCCESS;
}
