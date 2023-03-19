//
/*
Author: Derek Ni
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E7.16

Description: 
Write a program that carries out the following tasks:
Open a file with the name hello.txt.
Store the message “Hello, World!” in the file.
Close the file.
Open the same file again.
Read the message into a string variable and print it
*/

#include <climits>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;

void read(string filename){
    ifstream fin(filename);
    for (int i = 0; i < filename.length(); i++){

    }

}


int main(){
    ifstream fin("Hello.txt");
}