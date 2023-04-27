//
/*
Author: Derek Ni
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Project 2 B

Description: Task B
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Copy from Task A

int g_curr_size = 2;
int g_number_of_songs = 0;

string *g_song_names = new string[g_curr_size];
string *g_artist_names = new string[g_curr_size];
int *g_song_durations = new int[g_curr_size];
string *g_genres = new string[g_curr_size];

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

//End of Copy

/*
    @param genre              :   A string representing a genre
    @param(&) genreCount      :   An integer that will keep track of the number of songs
    @return                   :   A pointer to a dynamically allocated array of strings 
    @post                     :   Return a pointer to a dynamically allocated array of strings
                                  containing the names of the songs of given 'genre' and 
                                  update 'genreCount' to be the number of songs found.
                                  Return a pointer to an empty dynamically allocated array
                                  if no songs are found of the given 'genre'
    
    For example : Let's say we have the following 'g_song_names':
                  ["Killshot", "Takeover", "Spectre", "Ether", "No Title"]
                  
                  Let's say we have the following 'g_genres':
                  ["HipHop", "HipHop", "EDM", "HipHop", "JPop"]
                  
                  We try the following code with the above global-arrays:
                  int main(){
                    int count = 0;
                    string * genreSongs = getGenreSongs("HipHop", count);
                  }

                  In this case, 'genreSongs' will be pointing to the following:
                  ["Killshot", "Takeover", "Ether"]
                  The value of 'count' will be updated to 3 because there
                  are three "HipHop" songs on the playlist 
*/
string * getGenreSongs(string genre, int &genreCount){
    int x = g_number_of_songs;
    string *genreSongs = new string[x];
    genreCount = 0;

    if(x > 0){
        for (int i = 0; i < x; i++){
            if(g_genres[i] == genre){
                genreSongs[genreCount] = g_song_names[i];
                genreCount++;
            }
        }
    }
    return genreSongs;
}
/*
    @param duration             :   The integer duration of the songs
    @param(&) durationsCount    :   An integer that will keep track of the number of songs
    @param filter               :   An integer(0, 1 or 2) representing the comparision filter
                                    0 = greater-than, 1 = less-than, 2 = equal-to
    @return                     :   A pointer to a dynamically allocated array of strings 
    @post                       :   Return a pointer to a dynamically allocated array of strings
                                    of songs that are either greater-than, less-than or equal-to
                                    the given 'duration' based on given 'filter'. Update parameter
                                    'durationsCount' with the number of songs found. Return a 
                                    pointer to an empty dynamically allocated array if no songs
                                    are found with the given parameters

    For example : Let's say we have the following 'g_song_names':
                  ["Major Crimes", "Never Fade Away", "Circus Minimus", "4aem", "Reaktion"]

                  Let's say we have the following 'g_song_durations':
                  [3, 4, 3, 5, 2]

                  We try the following code with the above global-arrays:
                  int main(){
                    int greater = 0;
                    int less = 0;
                    int equal = 0;
                    string * longSongs = getSongsFromDuration(3, greater, 0);
                    string * shortSongs = getSongsFromDuration(3, less, 1);
                    string * mediumSongs = getSongsFromDuration(3, equal, 2);
                  }

                  After running the above code, 'longSongs' will be:
                  ["Never Fade Away", "4aem"]
                  The value of 'greater' will be 2 because there are two songs 
                  greater than 3 mins duration

                  Similarly, 'shortSongs' will be:
                  ["Reaktion"]
                  The value of 'less' will be 1 because there is only one song 
                  less than 3 mins duration

                  Finally, 'mediumSongs' will be:
                  ["Major Crimes", "Circus Minimus"]
                  The value of 'equal' will be 2 because there are 2 songs
                  equal to 3 mins duration      
*/
string * getSongsFromDuration(int duration, int &durationsCount, int filter){
    int x = g_number_of_songs;
    string *durationsSong = new string[x];
    durationsCount = 0;

    if(x>0){
        for(int i = 0; i < x; i++){
            if(filter == 0){
                if(g_song_durations[i] > duration){
                    durationsSong[durationsCount] = g_song_names[i];
                    durationsCount++;
                }
                
            }
            if(filter == 1){
                if(g_song_durations[i] < duration){
                    durationsSong[durationsCount] = g_song_names[i];
                    durationsCount++;
                }
                
            }
            if(filter == 2){
                if(g_song_durations[i] == duration){
                    durationsSong[durationsCount] = g_song_names[i];
                    durationsCount++;
                }
                
            }
        }
    }
    return durationsSong;
}
/*
    @param      :   An integer that will keep track of unique artists
    @return     :   A pointer to a dynamically allocated array of strings 
    @post       :   Return a pointer to a dynamically allocated array of strings
                    containing the names of unique artists in 'g_artist_names'
                    and update 'uniqueCount' parameter to be the number of
                    unique artists found
    
    For example : Let's say we have the following 'g_artist_names':
                  ["Eminem", "Eminem", "Jay Z", "Jay Z", "Nas"]
                  
                  We try the following code with this 'g_artist_names':
                  int main(){
                    int count = 0;
                    string * uniques = getUniqueArtists(count);
                  }

                  In this case, 'uniques' will be pointing to the following:
                  ["Eminem", "Jay Z", "Nas"]
                  The value of 'count' will be updated to 3 because there
                  are three unique artists on the playlist     
*/
string * getUniqueArtists(int &uniqueCount){
    int x = g_number_of_songs;
    string *uniqueArtists = new string[x];
    uniqueCount = 0;
    if(x > 0){
        for(int i = 0; i < x; i++){
            bool y = true;
            for (int j = 0; j < uniqueCount; j++){
                if(g_artist_names[i] == uniqueArtists[j]){
                    y = false;
                }
            }
            if (y){
                uniqueArtists[uniqueCount] = g_artist_names[i];
                uniqueCount++;
            }
        }
    }
    return uniqueArtists;
}
/* 
    @return     :   A string with the artist with most songs in playlist
    @post       :   Find the artist with the most songs in the playlist
                    If there are multiple such artists, return any one of them.
                    Return "NONE" if the playlist is empty

    For example : Let's say we have the following 'g_artist_names':
                  ["J. Cole", "J. Cole", "Kendrick", "Kendrick", "Kendrick"]
                  The favorite artist here is "Kendrick" because he has 3 songs
                  However, consider the following 'g_artist_names':
                  ["J. Cole", "J. Cole", "Kendrick", "Kendrick", "Drake"]
                  In this case, the favorite artist is either "J.Cole" or "Kendrick"
                  because both artists have 2 songs which is greater than any 
                  other artists in the playlist
*/
string getFavoriteArtist(){
    int c = 0, a = 0, sames = 1, y = g_number_of_songs;
    string artist, names;
    getUniqueArtists(c);
    int tally[c];

    if(y <= 0){
        return "NONE";
    }

    for(int i = 0; i < y; i++){
        if (g_artist_names[i] == g_artist_names[i+1]){
            artist = g_artist_names[i];
            sames++;
        } else {
            tally[a] = sames;
            a++;
            sames = 1;
        }
        
        if(tally[a-1] < sames){
            names = artist;
        }
    }

    for(int j = 0; j < c; j++){
        if (tally[j] > sames){
            sames = tally[j];
        }
    }
    return names;
}
