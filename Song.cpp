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

bool Song::operator ==(Song const &rhs)
{
   if (title != rhs.title) return false;
   if (artist != rhs.artist) return false;
   if (size != rhs.size) return false;
   else return true;
}

bool Song::operator <(Song const &rhs)
{
   // First compare the artists:
   if (artist < rhs.artist) return true;
   else if (artist > rhs.artist) return false;

   // Here, the two artists must be the same.
   // Now compare the two titles:
   if (title < rhs.title) return true;
   else if (title > rhs.title) return false;
   
   // Both the artists and the titles are the same.
   // Now compare the two sizes:
   if (size < rhs.size) return true;
   else if (size > rhs.size) return false;

   // Both songs are equal.  In this case, return false.
   return false;
}

bool Song::operator >(Song const &rhs)
{
   // First compare the artists:
   if (artist > rhs.artist) return true;
   else if (artist < rhs.artist) return false;

   // Here, the two artists must be the same.
   // Now compare the two titles:
   if (title > rhs.title) return true;
   else if (title < rhs.title) return false;
   
   // Both the artists and the titles are the same.
   // Now compare the two sizes:
   if (size > rhs.size) return true;
   else if (size < rhs.size) return false;

   // Both songs are equal.  In this case, return false.
   return false;
}

