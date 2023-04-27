//
/*
Author: Derek Ni
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Project 2 A

Description;
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int g_curr_size = 2;
int g_number_of_songs = 0;

string *g_song_names = new string[g_curr_size];
string *g_artist_names = new string[g_curr_size];
int *g_song_durations = new int[g_curr_size];
string *g_genres = new string[g_curr_size];

/*
    @post             :   Replace the old global
                          dynamically allocated arrays
                          with new dynamically allocated
                          arrays of twice the size 
                          ('g_curr_size' * 2). Update
                          'g_curr_size' accordingly.
                          Make sure you copy the contents
                          of the older arrays. Do this
                          for the following global-arrays:
                          'g_song_names', 'g_artist_names', 
                          'g_song_durations', 'g_genres'
*/
void allocateNew() {
    int x = g_curr_size * 2;
    string *a = new string[x];
    string *b = new string[x];
    int *c = new int[x];
    string *d = new string[x];

    for (int i = 0; i < g_curr_size; i++) {
        a[i] = g_song_names[i];
        b[i] = g_artist_names[i];
        c[i] = g_song_durations[i];
        d[i] = g_genres[i];
    }

    delete[] g_song_names;
    delete[] g_artist_names;
    delete[] g_song_durations;
    delete[] g_genres;

    g_song_names = a;
    g_artist_names = b;
    g_song_durations = c;
    g_genres = d;
    g_curr_size *= 2;

}

/*
    @param            :   The string with the 'filename'
    @post             :   Reads the song, artists,
                          song durations and genres into 
                          the global-arrays and set the 
                          value of 'g_number_of_songs'
                          to the number of songs read.
                          Call 'allocateNew()' to allocate 
                          an array of larger size if the 
                          dynamic arrays reach full 
                          capacity.
*/
void readSongs(string filename){
    ifstream fin;
    fin.open(filename);
    string song;
    int x;

    if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1);
    }

    while(getline(fin,song)){
        x = g_number_of_songs;

        if(x == g_curr_size){
        allocateNew();
        }
        
        g_song_names[x] = song.substr(0, song.find(':'));
        song = song.substr(song.find(':') + 1, song.length());

        g_artist_names[x] = song.substr(0, song.find('-'));
        song = song.substr(song.find('-') + 1, song.length());

        g_genres[x] = song.substr(0, song.find('-'));
        song = song.substr(song.find('-') + 1, song.length());

        g_song_durations[x] = stoi(song.substr(0, song.find(' ')));

        g_number_of_songs++;
    }
}

/*
int main() {
    readSongs("songs.txt");

    cout << "Number of songs: " << g_number_of_songs << endl;

    cout << "Current size of arrays: " << g_curr_size << endl;

    cout << "Song names: " << endl;
    for (int i = 0; i < g_number_of_songs; i++) {
        cout << g_song_names[i] << " ";
    }

    cout << "Artist names: " << endl;
    for (int i = 0; i < g_number_of_songs; i++) {
        cout << g_artist_names[i] << " ";
    }

    cout << "Song durations: " << endl;
    for (int i = 0; i < g_number_of_songs; i++) {
        cout << g_song_durations[i] << " ";
    }

    cout << "Genres: " << endl;
    for (int i = 0; i < g_number_of_songs; i++) {
        cout << g_genres[i] << " ";
    }

    return 0;
}
*/