/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

void add(Song &s, UtPod &t)
{
   int result = t.addSong(s);
   if (result == 0) cout << "Added ";
   else cout << "Failed to add ";
   cout << "(" << s.getTitle() << ", ";
   cout << s.getArtist() << ", ";
   cout << s.getSize() << ")\n";
   cout << "Memory Remaining: ";
   cout << t.getRemainingMemory() << "/" << t.getTotalMemory() << endl;
}

void remove(Song &s, UtPod &t)
{

   int result = t.removeSong(s);
   if (result == 0) cout << "Removed ";
   else cout << "Failed to remove ";
   cout << "(" << s.getTitle() << ", ";
   cout << s.getArtist() << ", ";
   cout << s.getSize() << ")\n";
   cout << "Memory Remaining: ";
   cout << t.getRemainingMemory() << "/" << t.getTotalMemory() << endl;
}

int main(int argc, char *argv[])
{
    UtPod t(30);

    Song s1("More Than a Feeling", "Boston", 4);
    Song s2("Hold the Line", "Toto", 4);
    Song s3("Any Way You Want It", "Journey", 3);
    Song s4("Red Barchetta", "Rush", 6);
    Song s5("Georgy Porgy", "Toto", 4);
    Song s6("Long Time", "Boston", 7);
    Song s7("Lowdown", "Boz Scaggs", 5);
    
    add(s1, t);
    add(s2, t);
    add(s3, t);
    add(s4, t);
    add(s5, t);
    add(s6, t);
    add(s7, t);

    cout << endl;
    t.showSongList();

    cout << "SHUFFLE SONGS" << endl;
    t.shuffle();
    t.showSongList();

    cout << "SHUFFLE SONGS AGAIN" << endl;
    t.shuffle();
    t.showSongList();

    cout << "SORT SONGS" << endl;
    t.sortSongList();
    t.showSongList();

    remove(s3, t);
    remove(s7, t);
    remove(s3, t);

    cout << endl;
    t.showSongList();

    cout << "CLEAR MEMORY" << endl;
    t.clearMemory();
    t.showSongList();

    cout << "ADD UNINITIALIZED SONGS" << endl;
    Song s8;
    add(s8, t);
    Song s9;
    add(s9, t);
    Song s10;
    add(s10, t);

    cout << endl;
    t.showSongList();

    cout << "SORT SONGS" << endl;
    t.sortSongList();
    t.showSongList();

    remove(s9, t);

    cout << endl;
    t.showSongList();

    cout << "CLEAR MEMORY" << endl;
    t.clearMemory();
    t.showSongList();

    cout << "ATTEMPT TO REMOVE FROM EMPTY POD" << endl;
    remove(s3, t);
    cout << endl;
    t.showSongList();

    cout << "ADD SEVERAL DUPLICATES" << endl;
    add(s1, t);
    add(s1, t);
    add(s1, t);
    add(s1, t);
   
    cout << endl;
    t.showSongList();

    remove(s1, t);
    remove(s1, t);
    cout << endl;
    t.showSongList();

    
    cout << "Initialize UtPod with 1000 MB" << endl;
    UtPod t2(1000);
    cout << "Total memory:" << t2.getTotalMemory() << endl;
    cout << "Remaining memory:" << t2.getRemainingMemory() << endl;
    cout << endl;

    cout << "Initialize UtPod with -5 MB" << endl;
    UtPod t3(-5);
    cout << "Total memory:" << t2.getTotalMemory() << endl;
    cout << "Remaining memory:" << t2.getRemainingMemory() << endl;
    cout << endl;

    cout << "Initialize a song with blank title" << endl;
    Song s_blank("", "", 0);
    add(s_blank, t3);

    return 0;
}
