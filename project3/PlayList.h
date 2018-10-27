/*
Thomas Westfall
10/14/18
CSCI 235 - Fall 2018
Project 3 - PlayList.h
Headers for PlayList.cpp
*/

#pragma once
#include "Song.h"
#include "LinkedSet.h"
class PlayList : public LinkedSet<Song>{

 private:
  Node<Song>* tail_ptr_; // Pointer to last node in the playlist
  Node<Song>* getPointerToLastNode() const; //method to get tail_ptr
  Node<Song>* getPointerTo(const Song& target, Node<Song>*& previous_ptr) const;
  //given a song, finds the pointer of the node where its stored in
  
 public:

     //default constructor
     PlayList();
     
     //parameterized constructor
     PlayList(const Song& a_song);

     //copy constructor
     PlayList(const PlayList& a_play_list);

     //destructor
     ~PlayList();
	
     //modifier functions
     bool add(const Song& new_song) override;
     bool remove(const Song& old_song) override;
     void loop();
     void unloop();
     
     //tostring (void though, uses tovector)
     void displayPlayList() const;


};
