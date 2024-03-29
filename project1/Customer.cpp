/*
Thomas Westfall
8/30/18
CSCI 235 - Fall 2018
Project 1 - Customer.cpp
This file contains the implementation of the methods needed for the customer.
The prototypes are in customer.hpp
*/

#include <iostream>
#include <string>
#include "Customer.hpp"
using namespace std;

//constructor
Customer::Customer(){
  name_ = "";
  defective_device_ = "";
  wait_time_ = 0;
}

Customer::Customer(string name, string device, int wait_time){
  name_ = name;
  defective_device_ = device;
  wait_time_ = wait_time;
}

//accessor functions
string Customer::getName(){
  return name_;
}

string Customer::getDevice(){
  return defective_device_;
}

int Customer::getWaitTime(){
  return wait_time_;
}

//modifier functions
void Customer::updateWaitTime(int new_wait_time){
  wait_time_ = new_wait_time;
}

