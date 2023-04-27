//
/*
Author: Derek Ni
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Project 2 C

Description: Task B
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Song{
    public:
        string name;
        string artist;
        int duration;
        string genre;   
};

int g_capacity = 2;
int g_size = 0;

Song *g_songs = new Song[g_capacity];

/*
    @post             :   Replace the old global
                          dynamically allocated array
                          'g_songs' with new dynamically
                          allocated array of twice the 
                          capacity ('g_capacity' * 2). 
                          Update 'g_capacity' accordingly.
                          Make sure you copy the contents
                          of the old array to the new one.
*/
void allocateNew(){
    g_capacity *= 2;
    Song *newSongs = new Song[g_capacity];
    for (int i = 0; i < g_size; i++){
        newSongs[i] = g_songs[i];
    }
    
    delete[] g_songs;
    g_songs = newSongs;

}

/*
    @param            :   The string with the 'filename'
    @post             :   Reads the song, artists,
                          song durations and genres into 
                          the 'g_songs' and sets the 
                          value of 'g_size' to the number 
                          of songs read. Call 'allocateNew()' 
                          where necessary similar to Task A.
*/


void readSongs(string filename){
    std::fstream fin;
    fin.open(filename);
    std::string junk, songs, artists, genre, duration;

    while(getline(fin, songs, ':') && getline(fin, artists, '-') && getline(fin, genre, '-') && getline(fin, duration, ' ') && getline(fin, junk)){ 
        if (g_size >= g_capacity){
            allocateNew();
        }
        
        g_songs[g_size].name = songs;
        g_songs[g_size].artist = artists;
        g_songs[g_size].genre = genre;
        g_songs[g_size].duration = stoi(duration);

        g_size++;

    }
}


/*
void readSongs(string filename) {
  
    ifstream file;
    file.open(filename);



 
    string line;
   while(getline(file, line))
    {
        if (g_size == g_capacity)
        {
            allocateNew();
        }
        g_songs[g_size].name = line.substr(0, line.find(':')); 
        line = line.substr(line.find(':') + 1, line.length());
        g_songs[g_size].artist = line.substr(0, line.find('-'));
        line = line.substr(line.find('-') + 1, line.length());
        g_songs[g_size].genre= line.substr(0, line.find('-'));
        line = line.substr(line.find('-') + 1, line.length());
        g_songs[g_size].duration = stoi(line.substr(0, line.find(' ')));
        g_size++;
    }
}
*/

// Now returns a dynamic array of 'Song' objects instead of a 'string' objects
Song * getSongsFromDuration(int duration, int &durationsCount, int filter){
    Song *durationsSong = new Song[g_capacity];
    durationsCount = 0;



    for(int i = 0; i < g_size; i++){
        if(filter == 0){
            if(g_songs[i].duration > duration){
                durationsSong[durationsCount] = g_songs[i];
                durationsCount++;
            }
                
        }
        if(filter == 1){
            if(g_songs[i].duration < duration){
                durationsSong[durationsCount] = g_songs[i];
                durationsCount++;                
            }
                
        }
        if(filter == 2){
            if(g_songs[i].duration == duration){
                durationsSong[durationsCount] = g_songs[i];
                 durationsCount++; 
            }       
        }

    }
    
    return durationsSong;

}



Song * getGenreSongs(string genre, int &genreCount){
        
    Song *genre_of_songs = new Song[g_size];
    genreCount = 0;

    for (int i = 0; i < g_size; i++){
        if (g_songs[i].genre == genre){
            genre_of_songs[genreCount] = g_songs[i];
            genreCount++;
        }
    }

    return genre_of_songs;
}

// Change the implementation since we are using 'Song' class
string * getUniqueArtists(int &uniqueCount){
    string *unique = new string[g_size];
    string *artist_list = new string [g_size];

    for (int i = 0; i < g_size; i++){
        artist_list[i] = g_songs[i].artist;
    }

    for (int j = 0; j < g_size; j++){
        for (int k = j + 1; k < g_size; k++){
            if (artist_list[j] == artist_list[k]){
                artist_list[j] = "Double";

            }
        }
    }

    for (int l = 0; l < g_size;){
        if (artist_list[l] != "Double"){
            unique[uniqueCount] = artist_list[l];
            uniqueCount++;
        }
    }

    return unique;
}

string getFavoriteArtist(){
    if (g_size == 0){
        return "NONE";
    }

    int maxCount = 0;
    string maxArtist = " ";


    for (int i = 0; i < g_size; i++){
        int count = 0;
        
        for (int j = i + 1; j < g_size; j++)
            {
                if (g_songs[i].artist == g_songs[j].artist)
                {
                    count++;
                }
            }

            if (count > maxCount)
            {
                maxCount = count;
                maxArtist = g_songs[i].artist;
            }
        }
    
    return maxArtist;
}

