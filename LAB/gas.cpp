/*
Author: Derek Ni
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E2.10 - Cost per 100 Miles

Description: The code asks for an input of 3 different integers: gallons in the tank, fuel effciency, and price of gas. 
Then the code will output thr cost per 100 miles and how far the car can go with the gas in the tank.
*/

#include <iostream>
using namespace std;

int main () {
    float gallons; float fuel; float price;
    cout << "The number of gallons of gas in a tank: ", cin >> gallons;
    cout << "The fuel effciency in miles per gallon: ", cin >> fuel;
    cout << "The price of gas per gallon: ", cin >> price;

    cout << "The cost per 100 miles is " << 100/fuel * price << endl;
    cout << "The car can go " << gallons*fuel << " with the gas in the tank" << endl;
    
    cout << endl;
}

