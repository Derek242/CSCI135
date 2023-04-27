//
/*
Author: Derek Ni
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E8.1

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
    ofstream fin;
    fstream x;
    string neww;

    fin.open("hello.txt");

    if (fin.fail()){
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    
    fin << "Hello, World!";
    fin.close();

    x.open("hello.txt");
    while (getline(x,neww)){
        cout << neww << endl;
    }

    

}

int main(){
    read("hello.txt");
}

