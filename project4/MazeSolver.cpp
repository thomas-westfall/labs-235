/*
Thomas Westfall
9/12/18
CSCI 235 - Fall 2018
Project 2 - Playlist.cpp
Implementation of the PlayList class, with headers from PlayList.h
*/


#include <iostream>
#include <string>
#include "MazeSolver.h"
using namespace std;

//constructor
MazeSolver::MazeSolver(string input_file){


}

//destructor
MazeSolver::~MazeSolver(){

}

//public functions
bool MazeSolver::mazeIsReady(){
  return false;
}

bool MazeSolver::solveMaze(){
  return false;
}

void MazeSolver::printSolution(){

}

//private functions
void MazeSolver::initializeMaze(int rows, int columns){

}

void MazeSolver::fillMaze(ifstream& input_stream){

}

void MazeSolver::initializeSolution(){

}

void MazeSolver::copyMazetoSolution(){

}

bool MazeSolver::extendPath(Position current_position){
  return false;
}

Position MazeSolver::getNewPosition(Position old_position, direction dir){
  return old_position;
}

bool MazeSolver::isExtensible(Position current_position, direction dir){
  return false;
}

