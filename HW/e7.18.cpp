//
/*
Author: Derek Ni
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E7.18

Description:  Define a structure Triangle that contains three Point members. Write a function that 
computes the perimeter of a Triangle. Write a program that reads the coordinates of 
the points, calls your function, and displays the result
*/

#include <iostream>
#include <cmath>
using namespace std;

//Copy from 7.16

struct Point{
    double x; 
    double y;

};

struct Triangle {
    Point a;
    Point b;
    Point c;
};

double distance(Point a, Point b){
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}


double perimeter(Triangle t){
    return distance(t.a, t.b) + distance(t.b, t.c) + distance(t.c, t.a);
}


int main(){
    Triangle t;
    cout << "Enter point a: ", cin >> t.a.x >> t.a.y;
    cout << "Enter point b: ", cin >> t.b.x >> t.b.y;
    cout << "Enter point c: ", cin >> t.c.x >> t.c.y;
    cout << "Perimeter: " << perimeter(t) << endl;
    return 0;

}

