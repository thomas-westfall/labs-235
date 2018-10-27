/*
Thomas Westfall
9/12/18
CSCI 235 - Fall 2018
Project 2 - Set.h
Inherits SetInterface.h, headers for Set.cpp
*/

#pragma once
#include "SetInterface.h"
template <class ItemType>

class Set : public SetInterface<ItemType>{
 private:
  static const int DEFAULT_SET_SIZE = 4;
  ItemType items_[DEFAULT_SET_SIZE];
  int item_count_;
  int max_items_;
  
  //helper function
  int getIndexOf(const ItemType& target) const;
  
 public:
  //constructor
  Set();

  //accessor functions
  int getCurrentSize() const;
  bool isEmpty() const;
  bool contains(const ItemType& anEntry) const;

  //modifier functions
  bool add(const ItemType& newEntry);
  bool remove(const ItemType& anEntry);
  void clear();

  //toVector (creates a vector with set data values)
  std::vector<ItemType> toVector() const;
};
#include "Set.cpp"

