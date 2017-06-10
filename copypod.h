/****************************************************
File Name: copypod.h

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

#ifndef COPYPOD_H
#define COPYPOD_H

#include "song.h"

// CopyPod class declaration
class CopyPod {
private:
    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;
    
    struct SongNode {
        Song s;
        SongNode *next;
    };
    
    SongNode *songs;      // the head pointer
    
    int memSize;
    
public:
    // constructor sets the head pointer to NULL and memory set to 512MB
    CopyPod();
    
    // memory set to 512MB if parameter 512 or greater is passed
    // memory set to parameter passed if less than 512 and positive
    CopyPod (int size);
    
    // destructor deletes list of songs
    ~CopyPod();
    
    // attempts to add song to end of list
    int addSong (Song const &song);
    
    // attempts to remove song from list
    int removeSong (Song const &song);
    
    // shuffles list of songs if there's 2 or more songs
    void shuffle();
    
    // prints current list of songs
    // Format: Artist, Title, Size(MB)
    void showSongList();
    
    // sorts list of songs in an array, replaces sorted songs back into linked list
    void sortSongList();
    
    // returns total memory of CopyPod
    int getTotalMemory();
    
    // returns the memory remaining in CopyPod that has not been used up
    int getRemainingMemory();    
    
    // returns the number of songs currently in CopyPod
    int getNumberOfSongs();
};

#endif /* COPYPOD_H */

