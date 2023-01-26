/*
Author: Derek Ni
Course: CSCI-135
Assignment: Lab 1 D

Description:
*/

#include <iostream>
using namespace std;

int main () {
    int year; int month; 
    cout << "Enter year: ", cin >> year;
    cout << "Enter month: ", cin >> month;
    if (year % 4 != 0) {
        if (month == 2){
            cout << "28 days";
        } else if (month % 2 !=0) {
            cout << "30 days";
        } else {
            cout << "31 days";
        }
    } else if (year % 100 != 0) {
        if (month == 2){
            cout << "29 days";
        } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            cout << "31 days";
 
        } else {
            cout << "30 days";
        }
    } else if (year % 400 != 0) {
        if (month == 2){
            cout << "28 days";
        } else if (month % 2 !=0) {
            cout << "30 days";
        } else {
            cout << "31 days";
        }
    } else {
        if (month == 2){
            cout << "29 days";
        } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            cout << "31 days";
 
        } else {
            cout << "30 days";
        }
    }
    cout << endl;


}