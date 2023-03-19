//
/*
Author: Derek Ni
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E7.16

Description: Define a structure Point. A point has an x- and a y-coordinate. 
Write a function double distance(Point a, Point b) that computes the distance 
from a to b. Write a program that reads the coordinates of the points, 
calls your function, and displays the result
*/

#include <iostream>
#include <cmath>
using namespace std;

struct Point{
    double x; 
    double y;
};

double distance(Point a, Point b){
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main(){
    Point a = {0,1};
    Point b = {1,2};
 
    cout << distance(a,b) << endl;
    return 0;
}
