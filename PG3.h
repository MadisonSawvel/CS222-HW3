
//Madison Sawvel

#ifndef _PG3_
#define _PG3_
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv); // the user gives the width and height they would like to make the maze. Then provides the blockades within those sizes. 
	//After the info is given, the maze is created and solved
void GetMaze();  //reads the maze entered in line by line and creates maze
void DisposeMaze(); //deletes the maze when it is no longer needed
void PrintMaze(char** M); //prints the maze the user made with the blockades and returns the shortest path 'X' can take
int height(); //returns the saved height
int width(); //returns the saved width
void Solve(); //Determines each path X is able to make in the maze and compares to determine which is the shortest one. After each step, the maze is added to the queue to determine next route
#endif
