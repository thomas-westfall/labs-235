#include <iostream>
#include "MazeSolver.cpp"
int main() {
  MazeSolver solver("InputA.txt");
 if(solver.mazeIsReady())
 {
   solver.solveMaze();

 solver.printSolution();
 }
 MazeSolver solverb("InputB.txt");
 if(solverb.mazeIsReady())
 {
   solverb.solveMaze();

 solverb.printSolution();
 }
  MazeSolver solverd("InputD.txt");
 if(solverd.mazeIsReady())
 {
   solverd.solveMaze();

 solverd.printSolution();
 }


 return 0;
} 
