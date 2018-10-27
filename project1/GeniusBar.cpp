/*
Thomas Westfall
8/30/18
CSCI 235 - Fall 2018
Project 1 - GeniusBar.cpp
This file contains the implementation of the methods needed for the Genius Bar.
The prototypes are in GeniusBar.hpp (which uses Customer.cpp methods)
*/

#include <iostream>
#include "GeniusBar.hpp"
using namespace std;

//constructor
GeniusBar::GeniusBar(){ 
  current_wait_time_ = 0;
  number_of_available_geniuses_ = TOTAL_NUMBER_OF_GENIUSES;
  number_of_customers_ = 0;
  Customer genius_bar_[MAX_NUMBER_OF_CUSTOMERS];
}

    
    //pre: number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS

    //post: add new_customer to genius_bar_ and increment current_wait_time_ by WAIT_TIME_INCREMENT

    //return: true if number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS, false otherwise

bool GeniusBar::addWaitingCustomer(Customer& new_customer){
  if (number_of_customers_ >= MAX_NUMBER_OF_CUSTOMERS){
    return false;
  }
  
  genius_bar_[number_of_customers_] = new_customer; //add customer to array
  current_wait_time_ += WAIT_TIME_INCREMENT; //update overall waittime
  new_customer.updateWaitTime(current_wait_time_); //update customer waittime
  number_of_customers_++; //increment customer

  return true;
    
}


    

    //pre: (number_of_customers_ > 0) && (number_of_available_geniuses_ > 0)

    //post: decrement number_of_customers_ and number_of_available_geniuses_

    //return: true if (number_of_customers_ > 0) && (number_of_available_geniuses_ > 0), false otherwise

bool GeniusBar::assignGeniusToCustomer(){
  //check if theres a customer and genius available
  if (number_of_customers_ > 0 && number_of_available_geniuses_ > 0)
    {
      number_of_customers_--; //decrement customers
      number_of_available_geniuses_--; //decrement geniuses
      return true;
    }
  return false; //no customer/genius available
}

    

    //pre: number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES

    //post: increment number_of_available_geniuses

    //return: true if number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES, false otherwise

bool GeniusBar::releaseGenius(){
  if (number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES)
	{
	  number_of_available_geniuses_++; //increments geniuses
	  return true;
	}
  return false; //all geniuses free
}

    

    //pre: number_of_customers_ > 0

    //post: increment the wait time of each customer on the genius_bar by WAIT_TIME_INCREMENT

    //return: true if number_of_customers_ > 0, false otherwise

bool GeniusBar::updateCustomersWaitTime(){
  if (number_of_customers_ > 0) //check if theres customers to update
    {
      //go through every customer and update its wait time
      for (int i = 0; i < number_of_customers_; i++) 
	{
	  genius_bar_[i].updateWaitTime(genius_bar_[i].getWaitTime() + WAIT_TIME_INCREMENT); //updates the current customer
	}
      return true; //done
	}
  return false; //no customers to update
}
