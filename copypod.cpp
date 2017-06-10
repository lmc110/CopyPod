/****************************************************
File Name: copypod.cpp

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

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
#include "copypod.h"
#include "song.h"

using namespace std;

int currentMem = 0;     // holds total used memory of CopyPod
int numOfSongs = 0;

/*
Function: CopyPod
 
Description:  Constructor sets songs pointer to NULL and
              memory size to 512.
 
Receives: none
Returns: none
*/
CopyPod::CopyPod() {
    memSize = 512;
    songs = NULL;
}
/*
Function: CopyPod
 
Description:  Assigns memory size to parameter passed if between
              0 and 512. Anything else will assign memory size to
              512.
 
Receives: size (int)
Returns: none
*/
CopyPod::CopyPod(int size) {
    songs = NULL;
    
    if (size > 0 && size <= 512) 
        memSize = size;
    else if (size > 512)
        memSize = 512;
    else 
        memSize = 512;
    
}
/*
Function: ~CopyPod
 
Description:  Deletes the entire list of songs. Frees memory
 
Receives: none
Returns: none
*/
CopyPod::~CopyPod() {
    SongNode *temp = songs;
    
    while (songs != NULL) {
        songs = songs->next;
        delete temp;
        temp = songs;
    }
}
/*
Function: addSong
 
Description:  Attempts to add song to copyPod.
              Returns 0 if successful.
              Returns -1 if not enough memory.
              Returns -2 if blank artist or title, and if invalid size
 
Receives: song (Song)
Returns: 0 (int), -1 (int), -2 (int)
*/
int CopyPod::addSong(const Song& song) {
    // test for blank title/artist in song, or invalid size
    if (song.getTitle().length() <= 0 || song.getArtist().length() <= 0 || song.getSize() <= 0) 
        return NOT_FOUND;
    // test for memory capacity or number of slots
    else if (currentMem + song.getSize() >= memSize) 
        return NO_MEMORY;
    
    SongNode *temp;
    
    if (songs == NULL) {   // checks if list is empty
        songs = new SongNode;
        temp = songs;
        temp->s = song;
        temp->next = NULL;
    }
    else {
        temp = songs;
        
        while (temp->next != NULL)      // traverses until end of list
            temp = temp->next;
        
        temp->next = new SongNode;
        temp = temp->next;
        temp->s = song;
        temp->next = NULL;
    }
    
    currentMem += song.getSize();      // adds size of song to the total used memory
    numOfSongs++;
    return SUCCESS;
    
}
/*
Function: removeSong
 
Description:  Attempts to remove song.
              Returns 0 if successful
              Returns -1 if nothing was removed
 
Receives: song (Song)
Returns: 0 (int), -1 (int)
*/
int CopyPod::removeSong(const Song& song) {
    SongNode *cursor;
    SongNode *prev;
    
    if (songs == NULL)      // checks if list is empty
        return -1;
    
    if (songs->s == song) {     // checks if song is first in list
        currentMem -= songs->s.getSize();
        cursor = songs->next;
        delete songs;
        songs = cursor;
        numOfSongs--;
        
        return 0;
    }
    else {
        cursor = songs;
        
        while (cursor->next != NULL) {
            prev = cursor;
            cursor = cursor->next;
            
            if (cursor->s == song) {
                currentMem -= cursor->s.getSize();
                prev->next = cursor->next;
                delete cursor;
                numOfSongs--;
                
                return 0;
            }
        }
    }
    
    return -1;
}
/*
Function: showSongList
 
Description:  Prints out the list of songs in the format
              of: Artist, Title, Size(MB).
 
Receives: none
Returns: none
*/
void CopyPod::showSongList() {
    for (SongNode *cursor = songs; cursor != NULL; cursor = cursor->next) {
        cout << setw(15) << left << cursor->s.getArtist()
                 << setw(16) << left << cursor->s.getTitle()
                << setw(1) << left << cursor->s.getSize() << endl;
    }
    cout << endl;
}
/*
Function: getTotalMemory
 
Description:  Returns the total memory of the copyPod that was
              passed by the user of the class.
 
Receives: none
Returns: memSize (int)
*/
int CopyPod::getTotalMemory() {
    return memSize;
}
/*
Function: getRemainingMemory
 
Description:  Returns the remaining memory of the copyPod that is
              not being used up.
 
Receives: none
Returns: The total memory minus the current memory being used.
*/
int CopyPod::getRemainingMemory() {
    return (memSize - currentMem);
}
/*
Function: sortSongList
 
Description:  Sorts the list of songs in order. Traverses through linked
              list and compares each song. If first pointer is greater
              than second pointer, the songs are swapped.
 
Receives: none
Returns: none
*/
void CopyPod::sortSongList() {
    for( SongNode *p1 = songs; p1 != NULL; p1 = p1->next )
      for( SongNode *p2 = p1; p2 != NULL; p2 = p2->next )
         if( p1->s > p2->s )
         {
            Song temp = p1->s;
            p1->s = p2->s;
            p2->s = temp;
         }
}
/*
Function: shuffle
 
Description:  Shuffles the list of songs in random order. Copies
              songs to an array and shuffles it. Shuffled songs
              are replaced onto the linked list.
 
Receives: none
Returns: none
*/
void CopyPod::shuffle() {
    if (numOfSongs < 2) {       // check if CopyPod contains at least 2 songs
        cout << "Not enough songs to shuffle" <<endl;
        return;
    }
    
    int count = 0;      // used to traverse through array
    
    Song array[numOfSongs];     // array to be shuffled
    SongNode *cursor = songs;
    
    // add songs to array
    for (int i = 0; i < numOfSongs; i++) {
        array[i] = cursor->s;
        cursor = cursor->next;
    }
    
    for (int i = 0; i < numOfSongs; i++) {
        int j = (rand() % numOfSongs);      // seeds random number
        if (array[i] == array[j])                     // prevents appearance of same song
            array[i] = array[j];
        else {
            Song temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    // replace shuffled songs in array into linked list
    for (SongNode *cursor = songs; cursor != NULL; cursor = cursor->next) {
        cursor->s = array[count];
        count++;
    }
}
/*
Function: getNumberOfSongs
 
Description:  Returns the current number of songs in the copyPod.
 
Receives: none
Returns: The number of current songs.
*/
int CopyPod::getNumberOfSongs() {
    return numOfSongs;
}