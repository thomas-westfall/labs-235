/*
Thomas Westfall
9/12/18
CSCI 235 - Fall 2018
Project 2 - Playlist.cpp
Implementation of the PlayList class, with headers from PlayList.h
*/
#include "Song.h"
#include "PlayList.h"

//default constructor
PlayList::PlayList() {
}

// paremeterized constructor
PlayList::PlayList(const Song& a_song){
  addSong(a_song);
}

//accessor functions
int PlayList::getNumberOfSongs() const{
  return playlist_.getCurrentSize();
}

bool PlayList::isEmpty() const{
  return playlist_.isEmpty();
}

//modifier functions
bool PlayList::addSong(const Song& new_song){
  return playlist_.add(new_song);
}

bool PlayList::removeSong(const Song& a_song){
  return playlist_.remove(a_song);
}

void PlayList::clearPlayList(){
  playlist_.clear();
}

//tostring (but void,uses cout)
void PlayList::displayPlayList() const{
  std::vector<Song> playlist = playlist_.toVector(); //its a vector
  for (int i = 0; i < playlist_.getCurrentSize(); i++){
    cout << "* Title: " << playlist[i].getTitle();
    cout << " * Author: " << playlist[i].getAuthor();
    cout << " * Album: " << playlist[i].getAlbum()<<" *\n";
  }
  cout << "End of playlist\n";
}
