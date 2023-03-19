/*
Author: Derek Ni
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1 D

Descrption: I did the final task 

*/
#include <climits>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

// Copy from Previous task
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
bool addWord(string word, string definition, string pos) {
  // Finds if the word exist in g_words
  if (getIndex(word) != -1) {
    return false;
  }
  // Sees is there is space at the end of the string array
  if (g_words[g_MAX_WORDS - 1].empty() == false) { //.empty() checks if the length of the string is 0
    return false;
  }
  for (int i = 0; i < (sizeof(g_words) / sizeof(g_words[0])); i++) {
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
//End Copy

string maskWord(string word){
    int count = 0;
    string x = "";
    count =  word.length();
    for (int j = 0; j < count; j++){
        x += "_";
        }
    return x;  
} 
int getTries(int difficulty){
    if (difficulty == 0){
        return 9;
    } else if (difficulty == 1){
        return 7;
    } else if (difficulty == 2){
        return 5;
    }
  return -1;
} 
void printAttempts(int tries, int difficulty){
    string count = ""; 
    for (int i = 0; i < tries; i++){
        count += "O";
    }
    for (int j = 0; j < getTries(difficulty) - tries; j++){
        count += "X";
    }
    cout << count;
} 


/*
    @param word       :   The string word from the dictionary
    @param letter     :   The char letter that that will be revealed
    @param(&) current :   The string representing a masked word
    @return           :   `true` if the `letter` exists in `word`,
                          otherwise return `false`  
    @post             :   If the given `letter` exists in `word`
                          reveal the `letter` in `current` masked word
                          and return `true`. Otherwise, return `false`

    For example : Let's say we have the following main function:
                  int main(){
                      string w = "g___";
                      cout << revealLetter("good", 'o', "g___") << endl;
                      cout <<  w << endl;
                  }
                  The first `cout` will print 1 because the letter 'o'
                  exists in "good". Thus, the function returned `true`.
                  The second `cout` will print "goo_". The variable `w`
                  has been modified by the function to reveal all the
                  `o`s in "good" resulting in "goo_"           
*/
bool revealLetter(string word, char letter, string &current){
    int worked = 0;
    current = maskWord(word);
    for (int i = 0; i < word.length(); i++){
        if (word[i] == letter){
            //add it to current
            current[i] = letter;
            worked++;
        } 
    }
    if (worked > 0){
        return true;
    } else {
        return false;
    }
}


int main() {
    string test= "____";
  readWords("text.txt");
  cout << "MAX_WORDS: " << g_MAX_WORDS << endl; 
  cout << "WORD_COUNT: " << g_word_count << endl;
  cout << "WORDS: " << endl;
//   for (int i = 0; i < g_word_count; i++){
//       cout << g_words[i] << " | ";
//     }
//   cout << endl << "POS: " << endl;
//   for (int i = 0; i < g_word_count; i++) {
//     cout << g_pos[i] << " | ";
//   }
//   cout << "Definitions: " << endl;
//   for (int i = 0; i < g_word_count; i++) {
//     std::cout << g_definitions[i] << " | ";
//   }
  revealLetter("good",'o',test);

  return 0;
}

string getRandomWord() {
    srand((unsigned) time(NULL));
    int index = rand() % g_word_count;
    return g_words[index];
}

// game-loop for Hangman
void gameLoop() {
    int difficulty, tries;
    string word, current;
    char letter;
    while (true) {
        cout << "Welcome to Hangman!" << endl;
        cout <<  "0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
        cin >> difficulty;
        while (difficulty < 0 || difficulty > 3) {
            cout <<  "Enough horseplay >_< !\n0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
            cin >> difficulty;
        }
        if (difficulty == 3) {
            cout << "If you're hangry, go grab a bite! See what I did there?" << endl;
            break;
        }
        word = getRandomWord();
        current = maskWord(word);
        tries = getTries(difficulty);
        while (tries != 0) {
            cout << "Life: ";
            printAttempts(tries, difficulty);
            cout << endl << "Word: "<< current << endl;
            cout << "Enter a letter: ";
            cin >> letter;
            
            if (!revealLetter(word, letter, current)) {
                tries--;
            }
            if (current == word) {
                break;
            }
            if (tries == 2) {
                cout << "The part of speech of the word is "<< getPOS(word) << endl;
            }
            if (tries == 1) {
                cout << "Definition of the word: " << getDefinition(word) << endl;
            }
        }
        if (tries == 0) {
            cout << "The word is \"" << word << "\". Better luck next time! You're getting the ..ahem.. hang of it." << endl;
        }
        else {
            cout << "Congrats!!!" << endl;
        }
    }
}