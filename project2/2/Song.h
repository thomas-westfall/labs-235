/*
Thomas Westfall
9/12/18
CSCI 235 - Fall 2018
Project 2 - Song.h
Headers for Song.cpp
*/

#pragma once
#include <string>

class Song
{
 private:
  std::string title_;
  std::string author_;
  std::string album_;
  
  public:
  Song(); //default constructor
  Song(const std::string& title, const std::string& author = "", const std::string& album = ""); //paremterized constructor

  //accessor functions
  std::string getTitle() const;
  std::string getAuthor() const;
  std::string getAlbum() const;
	
  //modifier functions
  void setTitle(std::string title);
  void setAuthor(std::string author);
  void setAlbum(std::string album);
	
  //overrided comparison function
  friend bool operator==(const Song& lhs, const Song& rhs);
};