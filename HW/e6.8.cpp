//
/*
Author: Derek Ni
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E6.8

Description: Comparing 2 arrays for same element order
*/

#include <iostream>
using namespace std;

bool equals(int a[], int a_size, int b[], int b_size){
    if(a_size != b_size){
        return false;
    }
    
    for (int i = 0; i < a_size; i++){
        if (a[i] != b[i]){
            return false;
        }
    }
    return true;
}

/*
int main(){
    int num[5] = {1,2,3,4,5};
    int num2[5] = {1,2,3,4,5};
    int num3[5] = {2,3,4,5,6};

    cout << equals(num,5,num2,5);
    cout << equals(num,5,num2,4);
    cout << equals(num,5,num3,5);

}
*/