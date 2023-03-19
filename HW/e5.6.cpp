//
/*
Author: Derek Ni
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E5.6

Description: Writes a code that returns the middle character(s)
*/

#include <iostream>
#include <string>
using namespace std;

string middle(string str){
        string neww = "";
        if (str.length() % 2 == 0){
            neww += str[str.length()/2 - 1];
            neww += str[str.length()/2];
        } else {
            neww += str[str.length()/2];
        }
    return neww;
}

/*
int main(){
    cout << middle("Evan") << endl;
    cout << middle("James") << endl;
}
*/