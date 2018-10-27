/*
Thomas Westfall
9/12/18
CSCI 235 - Fall 2018
Project 2 - Playlist.cpp
Implementation of the PlayList class, with headers from PlayList.h
*/

#include <iostream>
#include <string>
#include <vector>
#include "PlayList.h"
#include "Song.h"

PlayList::PlayList(){
}

PlayList::PlayList(const Song& a_song){
  addSong(a_song);
}

int PlayList::getNumberOfSongs() const{
  return 0;
}

bool PlayList::isEmpty() const{
  return false;
}

bool PlayList::addSong(const Song& new_song){
   new_song == new_song;
  return false;
}

bool PlayList::removeSong(const Song& a_song){
  a_song == a_song;
  return false;
}

void PlayList::clearPlayList(){
}

void PlayList::displayPlayList() const{
}
