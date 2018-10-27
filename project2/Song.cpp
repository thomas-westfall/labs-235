/*
Thomas Westfall
9/12/18
CSCI 235 - Fall 2018
Project 2 - Song.cpp
Implementation of the Song class, with headers from Song.h
*/

#include "Song.h"

//constructor
Song::Song(){
}

//parameterized constructor
Song::Song(const std::string& title, const std::string& author, const std::string& album){
  title_ = title;
  author_ = author;
  album_ = album;

}

//modifier functions
void Song::setTitle(std::string title){
  title_ = title;
}

void Song::setAuthor(std::string author){
  author_ = author;
}

void Song::setAlbum(std::string album){
  album_ = album;
}

//accessor functions
std::string Song::getTitle() const{
  return title_;
}

std::string Song::getAuthor() const{
  return author_;
}

std::string Song::getAlbum() const{
  return album_;
}

//operator (equality)
bool operator==(const Song& lhs, const Song& rhs){
  if(lhs.getAuthor() == rhs.getAuthor())
    if(lhs.getTitle() == rhs.getTitle())
      return (lhs.getAlbum() == rhs.getAlbum());

  return false;
}
