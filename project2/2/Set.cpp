/*
Thomas Westfall
9/12/18
CSCI 235 - Fall 2018
Project 2 - Set.cpp
Implementation of methods prototyped in Set.h, also implements SetInterface.h
*/

#include <iostream>
using namespace std;

//constructor
template <class ItemType>
Set<ItemType>::Set(){
  item_count_ = 0;
  max_items_ = DEFAULT_SET_SIZE;
}

//helper function
template <class ItemType>
int Set<ItemType>::getIndexOf(const ItemType& target) const{
  for (int i = 0; i < item_count_; i++){
    if (items_[i] == target)
      return i;
  }
  return -1;
}

//accessor functions

template <class ItemType>
int Set<ItemType>::getCurrentSize() const{
  return item_count_;
}

template <class ItemType>
bool Set<ItemType>::isEmpty() const{
  return item_count_ == 0;
}

template <class ItemType>
bool Set<ItemType>::contains(const ItemType& anEntry) const{
  return getIndexOf(anEntry) != -1;
  
}

//modifier functions
template <class ItemType>
bool Set<ItemType>::add(const ItemType& newEntry){
  //check if it can be added first
  if (item_count_ < max_items_ && !(contains(newEntry))){
    items_[item_count_] = newEntry;
     item_count_ = item_count_ + 1;
    return true;
  }
  return false;
}

template <class ItemType>
bool Set<ItemType>::remove(const ItemType& anEntry){
  int i = getIndexOf(anEntry);
  if (contains(anEntry)){
    item_count_ = item_count_ - 1;
    items_[i] = items_[item_count_];
    return true;
    }
  return false;
}

template <class ItemType>
void Set<ItemType>::clear(){
  item_count_ = 0;
}


//toVector (creates a vector with set data values)
template <class ItemType>
vector<ItemType> Set<ItemType>::toVector() const{
  vector<ItemType> ans;
  for (int i = 0; i < item_count_; i++)
    ans.push_back(items_[i]);
  return ans;
}
