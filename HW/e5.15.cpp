//
/*
Author: Derek Ni
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E5.14

Description: sort3(a,b,c) 
*/

#include <iostream>
using namespace std;

void sort3(int& a, int& b, int& c){
    while (a > b || b > c){
        if(a > b){ 
            swap(a,b); 
        }
        if (b > c){
            swap(b,c);
        } 
    }
}


/*
int main(){
    int u = 1;
    int v = 9;
    int w = 5;
    sort3(v,u,w);
}
*/