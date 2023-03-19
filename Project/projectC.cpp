/*
Author: Derek Ni
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1 C

Descrption: I did the third task 

*/
#include <climits>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;

// Copy from Task A & B
const int g_MAX_WORDS = 1000;
int g_word_count = 0;

string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];

void readWords(string filename) {
  string junk;
  ifstream fin(filename);
  if (fin.fail()) {
    cerr << "File can't be opened for reading." << endl;
    exit(1);
  }
  while (fin >> g_words[g_word_count] >> g_pos[g_word_count] >> junk) {
    fin.ignore(1, ' ');
    getline(fin, g_definitions[g_word_count]);
    g_word_count++;
  }
}

int getIndex(string word) {
  for (int i = 0; i < (sizeof(g_words) / sizeof(g_words[0])); i++) {
    if (g_words[i] == word) {
      return i;
    }
  }
  return -1;
}
string getDefinition(string word) {
  if (getIndex(word) == -1) {
    return "NOT_FOUND";
  } else {
    return g_definitions[getIndex(word)];
  }
}
string getPOS(string word) {
  if (getIndex(word) == -1) {
    return "NOT_FOUND";
  } else {
    return g_pos[getIndex(word)];
  }
}
int countPrefix(string prefix) {
  int count = 0;
  for (int j = 0; j < (sizeof(g_words) / sizeof(g_words[0])); j++) {
    if (prefix == g_words[j].substr(0, prefix.length())) {
      count++;
    }
  }
  return count;
}
// End Copy

/*
    @param word       :   The string with a new word
    @param definition :   The string with the definition of the
                          new `word`
    @param pos        :   The string with the pos of the new `word`
    @return           :   return `true` if the word is
                          successfully added to the dictionary
                          return `false` if failed (word already
                          exists or dictionary is full)
    @post             :   Add the given `word`, `definition`, `pos`
                          to the end of the respective
                          global-arrays.
                          The word should not be added to the
                          global-arrays if it already exists
                          or if the array reached maximum
                          capacity(`g_MAX_WORDS`).
                          Update `g_word_count` if the word is
                          successfully added
*/
bool addWord(string word, string definition, string pos) {
  // Finds if the word exist in g_words
  if (getIndex(word) != -1) {
    return false;
  }
  // Sees is there is space at the end of the string array
  if (g_words[g_MAX_WORDS - 1].empty() == false) { //.empty() checks if the length of the string is 0
    return false;
  }
  for (int i = 0; i <= g_word_count; i++) {
    if (g_words[i].empty()) {
      g_words[i] = word;
      g_definitions[i] = definition;
      g_pos[i] = pos;
      g_word_count++;
      return true;
    }
  }
  return false;
}

/*
    @param word       :   The string with the word that is to
                          be edited
    @param definition :   The string with the new definition of
                          the `word`
    @param pos        :   The string with the new pos of the `word`
    @return           :   return `true` if the word is successfully
                          edited, return `false` if the `word`
                          doesn't exist in the dictionary
    @post             :   Replace the given `word`'s  definition
                          and pos with the given `definition` and
                          `pos` (by modifying global-arrays
                          `g_definitions` and `g_pos`).
                          The modification will fail if the word
                          doesn't exist in the dictionary
*/
bool editWord(string word, string definition, string pos) {

  if (getIndex(word) == -1) {
    return false;
  } 

  for (int j = 0; j < (sizeof(g_words) / sizeof(g_words[0])); j++) {
    {
      if (j == getIndex(word)){
        g_definitions[j] = definition;
        g_pos[j] = pos;
        return true;
      }
    }
  }
  return false;
}
/*
    @param            :   The string with the word that is to
                          be removed
    @return           :   return `true` if the word is successfully
                          removed from the dictionary return `false`
                          if the word doesn't exist in the dictionary
    @post             :   Remove the given `word`, `word`'s
                          definition and `word`'s pos from the
                          respective global-arrays if the word
                          exists.
                          Update `g_word_count` if the word is
                          successfully removed
*/
bool removeWord(string word){
  if (getIndex(word) == -1){
    return false;
  }
  for (int k = 0; k <= g_word_count; k++){
    if (k == getIndex(word)){
      g_words[k] = "" ; 
      g_definitions[k] = "";
      g_pos[k] = "";
      g_word_count--;

      for (int z = k; z <= g_word_count; z++){
        g_words[z] = g_words[z+1];
        g_definitions[z] = g_definitions[z+1];
        g_pos[z] = g_pos[z+1];
      }

    }
  }
  return true;
}



int main() {
  readWords("text.txt");
  addWord("Bruh", "Bro", "Bruv");
  //editWord("Grumpy", "blah blah", "brrrrrrr");
  removeWord("Does");
  cout << "MAX_WORDS: " << g_MAX_WORDS << endl; 
  cout << "WORD_COUNT: " << g_word_count << endl;
  cout << "WORDS: " << endl;
  for (int i = 0; i < g_word_count; i++){
      cout << g_words[i] << " | ";
    }
  cout << endl << "POS: " << endl;
  for (int i = 0; i < g_word_count; i++) {
    cout << g_pos[i] << " | ";
  }
  cout << "Definitions: " << endl;
  for (int i = 0; i < g_word_count; i++) {
    std::cout << g_definitions[i] << " | ";
  }
  return 0;
}
