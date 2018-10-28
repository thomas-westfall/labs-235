#include <iostream>
#include "MazeSolver.cpp"
int main() {

 MazeSolver solver("input.txt");

 if(solver.mazeIsReady())
 {
 solver.solveMaze();

 solver.printSolution();
 }

 return 0;
} 
