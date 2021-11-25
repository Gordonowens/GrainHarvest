// GrainHarvest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <string>
#include <fstream>





using std::cout; using std::cin;
using std::endl; using std::string;
using std::filesystem::directory_iterator;
using namespace std;


class Order {
public:
    string orderName;

    Order(string x = "blank order") {
        orderName = x;
    }

    string getName() {

        return orderName;
    }

};


void getOrders(string path) {

    string myText;
    int numOrder = 0;
    Order orders[10];





    for (const auto& file : directory_iterator(path)) {
        //cout << file.path() << endl;
        ifstream MyReadFile(file.path());
        getline(MyReadFile, myText);
        
        orders[numOrder] = Order(myText);
        numOrder += 1;
    }

    for (int i = 0; i < numOrder; i++) {

        cout << orders[i].getName() << "\n";

    }
    

    
    
}

int main()
{
    string path = "orders/";
    getOrders(path);

    return EXIT_SUCCESS;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
