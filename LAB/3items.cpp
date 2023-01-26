/*
Author: Derek Ni
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E1.7 - Three Items

Description: The program ask for 3 inputs from the user and then outputs the 3 items each on new lines.
*/

#include <iostream>
using namespace std;

int main () {
    string a; string b; string c;
    cout << "Input first item: ", cin >> a;
    cout << "Input second item: ", cin >> b;
    cout << "Input third item: ", cin >> c;
    cout << a << endl; cout << b << endl; cout << c << endl;

    cout << endl;
}