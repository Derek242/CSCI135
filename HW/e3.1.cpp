//
/*
Author: Derek Ni
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E3.1 - Positive or Zero or Negative

Description: Program ask for user input and then determine if its positive, zero, and negative

*/

#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Give number: ", cin >> num;
    if (num > 0){
        cout << "Positive";
    } else if (num == 0){
        cout << "Zero";
    } else if (num < 0){
        cout << "Negative";
    }
    return 0;
}