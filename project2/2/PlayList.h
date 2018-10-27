/*
Thomas Westfall
9/12/18
CSCI 235 - Fall 2018
Project 2 - PlayList.h
Headers for PlayList.cpp
*/

#include "Set.h"
#include "Song.h"

class PlayList{
 private:
  Set<Song> playlist_;
  
 public:
  //default constructor
  PlayList();
  
  //parameterized constructor
  PlayList(const Song& a_song);
  
  //accessor functions
  int getNumberOfSongs() const;
  bool isEmpty() const;

  //modifier functions
  bool addSong(const Song& new_song);
  bool removeSong(const Song& a_song);
  void clearPlayList();
  void displayPlayList() const;

};