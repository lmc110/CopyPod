/****************************************************
File Name: copypod_driver.cpp

This program tests the storage functionality of the
copyPod. CopyPod can store any number of songs but not
exceed 512MB. Each song consists of a artist (string),
title (string), and size (int). Artist and titles cannot
be blank and size must be greater than zero. Several
functions will test functionalities such as adding and
removing songs, shuffling and sorting the list of songs,
and returning the total/remaining memory in copyPod. The
list of songs will be implemented by a linked list.
*****************************************************/
#include <cstdlib>
#include <iostream>
#include <string>
#include "song.h"
#include "copypod.h"

using namespace std;

void displayMenu();

int main(int argc, char** argv) {
    cout << "--------------------------" << endl
             << " Starting CopyPod " << endl
             << "--------------------------" << endl;
 
   CopyPod myPod;
    
    char choice;
    string artist;
    string song;
    string sizeStr;
    int size;

    displayMenu();
    
    
    
    while (choice != '9') {
        cout << endl
                 << "Press 'm' to see the menu choice." << endl
                 << "What do you want to do?" << endl;
        cin >> choice;
        
        switch(choice) {
            case '1':
                cout << "You have " << myPod.getNumberOfSongs() << " songs." << endl;
                break;
            case '2':
                cout << "What is the name of the artist? " << endl;
                cin >> artist;
                cout << "What is the name of the song? " << endl;
                cin >> song;
                cout << "What is the size of the song(MB)" << endl;
                cin >> sizeStr;
                
                size = atoi(sizeStr.c_str());
                myPod.addSong(Song(artist,song,size));
                cout << "Song successfully added." << endl;
                break;
            case '3':
                cout << "Name of song artist to remove? " << endl;
                cin >> artist;
                cout << "Name of song title to remove? " << endl;
                cin >> song;
                cout << "Size of song (MB)? " << endl;
                cin >> sizeStr;
                
                size = atoi(sizeStr.c_str());
                myPod.removeSong(Song(artist,song,size));
                cout << "Song successfully removed." << endl;
                break;
            case '4':
                myPod.shuffle();
                cout << "Song list shuffled." << endl;
                break;
            case '5':
                myPod.showSongList();
                break;
            case '6':
                cout << "Song list un-shuffled." << endl;
                break;
            case '7':
                cout << myPod.getTotalMemory() << endl;
                break;
            case '8':
                cout << myPod.getRemainingMemory() << endl;
                break;
            case '9':
                cout << "Shutting off.." << endl;
                break;
            case 'm':
                displayMenu();
                break;
            default:
                cout << "Pleas choose a valid option." << endl;
                break;
        }
    }

    return 0;
}

void displayMenu() {
    cout << endl
            << "1.      Show current number of songs" << endl
            << "2.      Add a new song" << endl
            << "3.      Remove a song" << endl
            << "4.      Shuffle songs" << endl
            << "5.      Show all songs" << endl
            << "6.      Un-shuffle songs" << endl
            << "7.      Show the total memory size" << endl
            << "8.      Show remaining memory" << endl
            << "9.      Shut off (End program)" << endl;
}
