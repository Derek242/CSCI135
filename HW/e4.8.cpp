//
/*
Author: Derek Ni
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E4.8 - 1 character per line

Description: The program takes a user's word and then prints out each character in a seperate line
*/
#include <iostream>
using namespace std;

int main () {
    string word;
    cout << "Give word: ", cin >> word;
    for (int i = 0; i < word.length(); i++){
        cout << word[i] << endl;
        
    }
    return 0;
}