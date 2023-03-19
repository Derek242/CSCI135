//
/*
Author: Derek Ni
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E7.1

Description: that receives two pointers and sorts the values to which 
they point. 
*/

#include <iostream>
using namespace std;

void sort2(double* p, double* q){
    if (*p > *q){
        double x;
        x = *p;
        *p = *q;
        *q = x;
    }
}
