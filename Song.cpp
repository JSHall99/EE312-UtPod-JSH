/*
 * File:    Song.cpp
 * Author:  Jackson S. Hall
 * EID:     jsh3647
 * Date:    3/28/19
 */

#include "Song.h"

using namespace std;

Song::Song()
{
   title = "No Title";
   artist = "No Artist";
   size = 1;
}

Song::Song(string _title, string _artist, int _size)
{
   if (_title.length() > 0) title = _title;
   else title = "No Title"; 
   if (_artist.length() > 0) artist = _artist;
   else artist = "No Artist";
   if (_size > 0) size = _size;
   else size = 1;
}

string Song::getTitle() const
{
   return title;
}

string Song::getArtist() const
{
   return artist;
}

int Song::getSize() const
{
   return size;
}

void Song::setTitle(string _title)
{
   if (_title.length() > 0) title = _title;
}

void Song::setArtist(string _artist)
{
   if (_artist.length() > 0) artist = _artist;
}

void Song::setSize(int _size)
{
   if (_size > 0) size = _size;
}


