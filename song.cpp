/****************************************************
File Name: song.cpp

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
#include "song.h"

/*
Function: Song
 
Description:  Constructor initializes title and artist to 'blank'.
              Size is set to 0.
 
Receives: none
Constants: none
Returns: none
*/
Song::Song () {
    title == "";
    artist == "";
    size = 0;
}

/*
Function: Song
 
Description:  Constructor assigns song artist, title, and size.
 
Receives: artist (string), title (string), size (int)
Constants: none
Returns: none
*/
Song::Song (string artist, string title, int size) {
    this->title = title;
    this->artist = artist;
    this->size = size;
}

/*
Function: setTitle
 
Description:  Assigns song title.
 
Receives: title (string)
Constants: none
Returns: none
*/
void Song::setTitle (string title) {
    this->title = title;
}

/*
Function: setArtist
 
Description:  Assigns song artist.
 
Receives: artist (string)
Constants: none
Returns: none
*/
void Song::setArtist (string artist) {
    this->artist = artist;
}

/*
Function: setSize
 
Description:  Assigns song size in 'MB'.
 
Receives: size (int)
Constants: none
Returns: none
*/
void Song::setSize(int size) {
    this->size = size;
}

/*
Function: getTitle
 
Description:  Returns the song title.
 
Receives: none
Constants: none
Returns: title (string)
*/
string Song::getTitle() const
{
   return title;
}
 
/*
Function: getArtist
 
Description:  Returns the song artist.
 
Receives: none
Constants: none
Returns: artist (string)
*/
string Song::getArtist() const
{
   return artist;
}
 
/*
Function: getSize
 
Description:  Returns the song size.
 
Receives: none
Constants: none
Returns: size (int)
*/
int Song::getSize() const
{
   return size;
}
 
/*
Function: operator ==
 
Description: Overloads the operator '=='
 
Receives: none
Constants: none
Returns: none
*/
bool Song::operator == ( Song const &rhs )
{
   return ( artist == rhs.artist &&
           title == rhs.title &&
           size == rhs.size );
}
 
/*
Function: operator <
 
Description: Overloads the operator '<'
 
Receives: none
Constants: none
Returns: none
*/
bool Song::operator < ( Song const &rhs )
{
   if( artist == rhs.artist )
      return( title < rhs.title );
 
   return( artist < rhs.artist );
}
 
/*
Function: operator >
 
Description: Overloads the operator '>'
 
Receives: none
Constants: none
Returns: none
*/
bool Song::operator > ( Song const &rhs )
{
   if( artist == rhs.artist )
      return( title > rhs.title );
 
   return( artist > rhs.artist );
}