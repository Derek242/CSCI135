/*
Author: Derek Ni
Course: CSCI-135
Instructor: Micheal Zamansky
Assignment: Lab 2 B

Description: Taking in the lowest number and the highest 
number and then stating each interval from lowest to highest
*/

#include <iostream> 
using namespace std;

int main () {
    int L; int U;
    cout << "Please enter L: ", cin >> L;
    cout << "Please enter U: ", cin >> U;

    for (int i = L; i < U; i++){
        cout << i << "  ";
    }
 
}

