/*
 * File:    UtPod.cpp
 * Author:  Jackson S. Hall
 * EID:     jsh3647
 * Date:    3/28/19
 */

#include <iostream>
#include "UtPod.h"

using namespace std;

UtPod::UtPod()
{
   podMemSize = MAX_MEMORY;
   podMemRem = podMemSize;
   songs = NULL; // Initialize linked list pointer
}

UtPod::UtPod(int size)
{
   if (size > MAX_MEMORY || size <= 0) {
      podMemSize = MAX_MEMORY;
   }
   else {
      podMemSize = size;
   }
   
   podMemRem = podMemSize;
   songs = NULL; // Initialize linked list pointer
}

int UtPod::addSong(Song const &s)
{
   // Check if there is enough memory available on the UtPod to add
   // the song.
   if (s.getSize() > podMemRem) return NO_MEMORY;

   // Otherwise, add the new song to the front of the linked list
   SongNode *oldHead = songs;
   songs = new SongNode;
   songs->s = s;
   songs->next = oldHead;
   podMemRem -= s.getSize(); // Decrement remaining memory
   return SUCCESS;
}

int UtPod::removeSong(Song const &s)
{
   SongNode *nextNode = songs;
   SongNode *prevNode = NULL;

   // Traverse the linked list
   while (nextNode != NULL) {

      // If the song is found...
      if (nextNode->s == s) {

         // Remove the node from the list
         // Case 1: This is the first node in the list
         if (prevNode == NULL) {
            songs = nextNode->next;
            delete nextNode;
         }
         // Case 2: This is any other node in the list (prevNode != NULL)
         else {
            prevNode->next = nextNode->next;
            delete nextNode;
         }
         
         // Update available memory
         podMemRem += s.getSize();
         return SUCCESS;
      }

      prevNode = nextNode;
      nextNode = nextNode->next;
   }
   return NOT_FOUND;
}

void UtPod::shuffle()
{
   return;
}

void UtPod::showSongList()
{
   cout << "------------------------\n";
   cout << "Title, Artist, Size (MB)\n";
   cout << "------------------------\n";
   SongNode *nextNode = songs;
   while (nextNode != NULL) {
      cout << nextNode->s.getTitle() << ", ";
      cout << nextNode->s.getArtist() << ", ";
      cout << nextNode->s.getSize() << endl;
      nextNode = nextNode->next;
   }
   cout << "------------------------\n\n";
}

void UtPod::sortSongList()
{
   return;
}

void UtPod::clearMemory()
{
   return;
}

UtPod::~UtPod()
{
   // Deallocate each node of the linked list
   SongNode *currentNode = songs;
   while (currentNode != NULL) {
      SongNode *nextNode = currentNode->next;
      delete currentNode;
      currentNode = nextNode;
   }
}

