/*
Thomas Westfall
9/12/18
CSCI 235 - Fall 2018
Project 2 - Playlist.cpp
Implementation of the PlayList class, with headers from PlayList.h
*/



#include "MazeSolver.h"
using namespace std;

//constructor
MazeSolver::MazeSolver(string input_file){
  ifstream is(input_file);  
  if(is.is_open()){
    int temp;
    is >> temp;
    maze_rows_ = temp;
    is >> temp;
    maze_columns_ = temp;

    initializeMaze(maze_rows_, maze_columns_);
    fillMaze(is);
    maze_ready = true;
    is.close();

    initializeSolution();
    
}
  
  else
    cout<<"Cannot read from input_file"<<endl;

}

//destructor
MazeSolver::~MazeSolver(){
  
  if(maze_ready){
    for(int i = 0; i < maze_rows_; i++){
      for(int j = 0; j < maze_columns_; j++){
	//delete maze_[i][j];
	//delete solution_[i][j];
      }

      
      delete[] maze_[i];
      //delete[] solution_[i];
    }
    delete[] maze_;
    //delete[] solution_;

  }


}


//public functions
bool MazeSolver::mazeIsReady(){
  return maze_ready;
}

bool MazeSolver::solveMaze(){ //assume its not a 1 by 1 maze (just has $)
  
  //sets first position to > if there are ways to go
  //would push the positions (1,0) or (0,1) (if they were '_') twice if
  //position (0,0) wasnt accounted for separately
  if(backtrack_stack_.empty()){
    cout<<"This maze has no solution."<<endl;
    maze_[0][0] = '@';
    return false;
  }
  
  Position curpos = backtrack_stack_.top();
  solution_[0][0] = '>';
  
    
  while(!backtrack_stack_.empty()){
    if(solution_[curpos.row][curpos.column] == '$'){
      cout<<"Found the exit!!!"<<endl;
      return true;
    }
    else{
      if(isExtensible(curpos, SOUTH) && isExtensible(curpos, EAST)){
	extendPath(curpos);
	solution_[curpos.row][curpos.column] = '>';
	curpos = backtrack_stack_.top();
      }
      else{
	if(extendPath(curpos)){
	  solution_[curpos.row][curpos.column] = '>';
	  curpos = backtrack_stack_.top();
	}

      
      else{ //cannot move forward
	maze_[curpos.row][curpos.column] = 'X';
	solution_[curpos.row][curpos.column] = '@';
	backtrack_stack_.pop(); //move back a step
	if(!backtrack_stack_.empty())
	  curpos = backtrack_stack_.top();
      }
      
      }
      
    }
  }

  cout<<"This maze has no solution."<<endl;
  solution_[0][0] = '@';
  return false;
}

void MazeSolver::printSolution(){
  cout<<"The solution to this maze is:"<<endl;
   for(int i = 0; i < maze_rows_; i++){
      for(int j = 0; j < maze_columns_; j++){
	cout<<solution_[i][j]<<" ";
      }
      cout<<endl;
    }
   cout<<endl;
}

//private functions
void MazeSolver::initializeMaze(int rows, int columns){
  maze_ = new char *[rows];
  for(int i = 0; i < rows; i++)
    maze_[i] = new char[columns];
}

void MazeSolver::fillMaze(ifstream& input_stream){
  char tempc;
  for(int i = 0; i < maze_rows_; i++){
    for(int j = 0; j < maze_columns_; j++){
      input_stream >> tempc;
      maze_[i][j] = tempc; 
    }
  }
}

void MazeSolver::initializeSolution(){
  solution_ = new char *[maze_rows_];
  for(int i = 0; i < maze_rows_; i++)
    solution_[i] = new char[maze_columns_];
  copyMazetoSolution();
  Position start = {0,0};
  extendPath(start);
}

void MazeSolver::copyMazetoSolution(){
  solution_ = maze_;
}

bool MazeSolver::extendPath(Position current_position){
  bool ans = false;
  if(isExtensible(current_position, SOUTH)){
    backtrack_stack_.push(getNewPosition(current_position, SOUTH));
    ans = true;
  }
  
  if(isExtensible(current_position, EAST)){
    backtrack_stack_.push(getNewPosition(current_position, EAST));
    ans = true;
  }
  
  return ans;
}

Position MazeSolver::getNewPosition(Position old_position, direction dir){
  Position ans =  old_position;
   if(dir == SOUTH)
    ans.row = ans.row + 1;
  if(dir == EAST)
    ans.column = ans.column + 1;
  
  return ans;
    
}

bool MazeSolver::isExtensible(Position current_position, direction dir){
  if((current_position.row + 1 < maze_rows_ && dir == SOUTH) && ((maze_[current_position.row + 1][current_position.column] == '_') || (maze_[current_position.row+1][current_position.column] == '$')))
    return true;
  if((current_position.column + 1 < maze_columns_ && dir == EAST) && ((maze_[current_position.row][current_position.column + 1] == '_') || (maze_[current_position.row][current_position.column + 1] == '$')))
    return true;
  
  return false;
}

