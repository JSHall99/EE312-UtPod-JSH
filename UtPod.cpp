/*
 * File:    UtPod.cpp
 * Author:  Jackson S. Hall
 * EID:     jsh3647
 * Date:    3/28/19
 */

#include <iostream>
#include <cstdlib> // For random number generation
#include <ctime> // For seeding the random number generator
#include "UtPod.h"

using namespace std;

UtPod::UtPod()
{
   podMemSize = MAX_MEMORY;
   srand(time(0)); // Seed the random number generator
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
   
   songs = NULL; // Initialize linked list pointer
}

int UtPod::addSong(Song const &s)
{
   // Check if there is enough memory available on the UtPod to add
   // the song.
   if (s.getSize() > getRemainingMemory()) return NO_MEMORY;

   // Otherwise, add the new song to the front of the linked list
   SongNode *oldHead = songs;
   songs = new SongNode;
   songs->s = s;
   songs->next = oldHead;
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
         
         return SUCCESS;
      }

      prevNode = nextNode;
      nextNode = nextNode->next;
   }
   return NOT_FOUND;
}

void UtPod::shuffle()
{
   // Generate an array of n random numbers, where n is the number of songs
   int n = getNumSongs();
   int *randArray = new int[n];
   for (int i = 0; i < n; i++) {
      randArray[i] = rand();
   }

   // Sort the corresponding elements of the linked list in parallel with
   // the array of random numbers.  This randomizes the elements in the
   // linked list.

   // Selection Sort
   // Traverse the array with cursor
   for (int cursor = 0; cursor < n-1; cursor++) {

      // Find the smallest element (located at minIndex) at or to the right
      // of cursor
      int minIndex = cursor;
      for (int i = cursor+1; i < n; i++) {
         if (randArray[i] < randArray[minIndex]) {
            minIndex = i;
         }
      }
      
      // Swap the songs corresponding to cursor and minIndex
      SongNode *node1 = songs;
      for (int i = 0; i < cursor; i++) {
         node1 = node1->next;
      }

      SongNode *node2 = songs;
      for (int i = 0; i < minIndex; i++) {
         node2 = node2->next;
      }

      swap(node1->s, node2->s);

      // Also swap the elements in randArray
      int temp = randArray[cursor];
      randArray[cursor] = randArray[minIndex];
      randArray[minIndex] = temp;
   }

   delete[] randArray;

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

void UtPod::swap(Song &s1, Song &s2)
{
   Song temp = s1;
   s1 = s2;
   s2 = temp;
}

void UtPod::sortSongList()
{
   // Selection Sort

   // Traverse the linked list with cursor
   SongNode *cursor = songs;
   while (cursor != NULL) {
      // Find the smallest element at or to the right of cursor
      SongNode *i = cursor->next;
      SongNode *min = cursor;
      while (i != NULL) {
         if (i->s < min->s) min = i;
         i = i->next;
      }

      // Swap the smallest element found with cursor
      swap(min->s, cursor->s);

      cursor = cursor->next;
   }

   return;
}

void UtPod::clearMemory()
{
   // Deallocate each node of the linked list
   SongNode *currentNode = songs;
   while (currentNode != NULL) {
      SongNode *nextNode = currentNode->next;
      delete currentNode;
      currentNode = nextNode;
   }
   songs = NULL;

   return;
}

int UtPod::getRemainingMemory()
{
   int podMemRem = podMemSize;
   SongNode *currentNode = songs;
   while (currentNode != NULL) {
      podMemRem -= currentNode->s.getSize();
      currentNode = currentNode->next;
   }

   return podMemRem;
}

int UtPod::getNumSongs()
{
   int numSongs = 0;
   SongNode *currentNode = songs;
   while (currentNode != NULL) {
      numSongs++;
      currentNode = currentNode->next;
   }

   return numSongs;
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

