//
/*
Author: Derek Ni
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E6.18

Description: Write a function
vector<int> append(vector<int> a, vector<int> b)
that appends one vector after another. For example, if a is
1 4 9 16
and b is
9 7 4 9 11
then append returns the vector
1 4 9 16 9 7 4 9 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> append(vector<int> a, vector<int> b){
    for (int i = 0; i < b.size(); i++){
        a.push_back(b[i]);
    }

    return a;
}

