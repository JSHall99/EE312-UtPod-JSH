/*
 * File:   Song.h
 * Author: Jackson S. Hall
 * EID:    jsh3647
 * Date:   3/28/19
 * The song class stores the title, artist, and size of a song.
 */


#ifndef SONG_H
#define SONG_H

#include <string>

using namespace std;

class Song
{
   private:
      string title;
      string artist;
      int size;

   public:
      // Default constructor
      Song();

      // Constructor with parameters
      Song(string _title, string _artist, int _size);

      // Functions for accessing/setting instance variables
      // "const" means that the functions don't change the class's
      // instance variables.
      string getTitle() const;
      string getArtist() const;
      int getSize() const;
      
      // _title must have length greater than 0.  Otherwise, do nothing.
      void setTitle(string _title);

      // _artist must have length greater than 0.  Otherwise, do nothing.
      void setArtist(string _artist);

      // _size must be a positive integer.  Otherwise, do nothing.
      void setSize(int _size);
};

#endif

