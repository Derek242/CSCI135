/*
Author: Derek Ni
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1 A

Descrption: I did the first task 

*/
#include <iostream>
#include <fstream>
using namespace std;
/*
@param            :   The string with the `filename`
@post             :   Reads the words, definitions pos into the global-arrays 
and set the value of `g_word_count`to the number of words read
*/
const int g_MAX_WORDS = 1000;
int g_word_count = 0;

string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];

void readWords(string filename){
    string junk;
    ifstream fin(filename);
    if (fin.fail()){
        cerr << "File can't be opened for reading." << endl;
        exit(1); 
    }
    while (fin >> g_words[g_word_count] >> g_pos[g_word_count] >> junk){
        fin.ignore(1,' ');
        getline(fin,g_definitions[g_word_count]);
        g_word_count++;
    }

}


/*
int main (){
    readWords("text.txt");
        cout << g_MAX_WORDS << "\t";
    for (int i = 0; i < 5; i++){
        cout << g_words[i] << "\t";
        cout << g_pos[i] << "\t" ;
        cout << g_definitions[i] << "\t";
        cout << "\n";
    }
    return 0;
}
*/