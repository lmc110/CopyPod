/****************************************************
File Name: song.h

This program tests the storage functionality of the
copyPod. CopyPod can store any number of songs but not
exceed 512MB. Each song consists of a artist (string),
title (string), and size (int). Artist and titles cannot
be blank and size must be greater than zero. Several
functions will test functionalities such as adding and
removing songs, shuffling and sorting the list of songs,
and returning the total/remaining memory in copyPod. The
list of songs will be implemented by a Linked List..
*****************************************************/

#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>

using namespace std;

// Song class declaration
class Song {
    
private: 
    string title;
    string artist;
    int size;
    
public:
    // constructor initializes title and artist to 'blank' with size to 0.
    Song ();
    
    // constructor assigns song artist, title, and size
    Song (string artist, string title, int size);
    
    // assigns song title
    void setTitle (string title);
    
    // assigns song artist
    void setArtist (string artist);
    
    // assigns song size
    void setSize (int size);
    
    // returns song title
    string getTitle() const;
    
    // returns song artist
    string getArtist() const;
    
    // returns song size
    int getSize() const;
    
    // overloads the operator '=='
    bool operator == (Song const &rhs);
    
    // overloads the operator '<'
    bool operator < (Song const &rhs);
    
    // overloads the operator '>'
    bool operator > (Song const &rhs);
    
};

#endif /* SONG_H */

