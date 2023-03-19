/*
Author: Derek Ni
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1 B

Descrption: I did the second task 

*/

//copy from Task A
#include <iostream>
#include <fstream>
using namespace std;

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
//End of copy

/*
    @param            :   The string with a query word
    @return           :   Integer index of the word in`g_words` global-array. Returns
-1 if the word is not found
    @post             :   Find the index of given `word`in the `g_words` array. Return -1 if word is not in the array
*/
int getIndex(string word){
    for (int i = 0; i < (sizeof(g_words)/sizeof(g_words[0])); i++){
        if (g_words[i] == word){
            return i;
        } 
        
    }
    return -1;
}


/*
    @param            :   The string with a query word
    @return           :   Return the string definition of the word from  `g_definitions`
global-array. Return "NOT_FOUND" if word doesn't exist in the dictionary
    @post             :   Find the definition of the given `word` Return "NOT_FOUND" otherwise
*/
string getDefinition(string word){
    if (getIndex(word) == -1){
        return "NOT_FOUND";
    } else{
        return g_definitions[getIndex(word)];
    }
}

/*
    @param            :   The string with a query word
    @return           :   Return the string part-of-speech(pos) from the `g_pos` global-array. 
    Return "NOT_FOUND" if the word doesn't exist in the dictionary.
    @post             :   Find the pos of the given `word` Return "NOT_FOUND" otherwise
*/
string getPOS(string word){
    if (getIndex(word) == -1){
        return "NOT_FOUND";
    } else{
        return g_pos[getIndex(word)];
    }
}

/*
    @param            :   The string prefix of a word (the prefix can be of any length)
    @return           :   Integer number of words found that starts with the given `prefix`
    @post             :   Count the words that start with the given `prefix`
*/
int countPrefix(string prefix){
    int count = 0;
    for (int j = 0; j < (sizeof(g_words)/sizeof(g_words[0])); j++){
        if (prefix == g_words[j].substr(0,prefix.length())){
            count++;
        }
    }
    return count; 
}

/*
int main(){
    readWords("text.txt");
    cout << getDefinition("Professor") << "\n";
    cout << getIndex("Professor") << "\n";
    cout << countPrefix("Professor");
    cout << "\n";

    return 0;
}
*/