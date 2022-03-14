
//Madison Sawvel

#include <iostream>
#include <string>
#include <cstdlib>
#include "PG3.h"
#include "Queue.h"

using namespace std;

char** Maze; //pointer to a pointer that points to Maze
int w, h; //creates ints to be used as width and height later on
Queue* Q; //creates queue 

int main(int argc, char** argv) { // the user gives the width and height they would like to make the maze. Then provides the blockades within those sizes. 
	//After the info is given, the maze is created and solved
	string wth;
	string hght;
	cout << "Enter the width of the maze: " << endl;
	getline(cin, wth);
	cout << "Enter the height of the maze: " << endl;
	getline(cin, hght);
	w = stoi(wth);	
	h = stoi(hght);
	cout << "Enter the maze you'd like to solve " << endl;
	GetMaze();
	Solve();
	PrintMaze(Maze);

}
void GetMaze() { //reads the maze entered in line by line and creates maze
	Maze = new char* [h];
	string MRow;
	for (int i = 0; i < h; i++) {
		getline(cin, MRow);
		Maze[i] = new char();
		for (int j = 0; j < MRow.length(); j++) {
			Maze[i][j] = MRow[j]; 
		}
	}
}
void DisposeMaze() { //deletes the maze when it is no longer needed
	for (int i = 0; i < h; i++)
		delete[] Maze[i];
	delete[] Maze;
}
void PrintMaze(char** M) { //prints the maze the user made with the blockades and returns the shortest path 'X' can take
	cout << "#####################" << endl;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << M[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "#####################" << endl;
}
int height() { //returns the saved height
	return h;
}
int width() { //returns the saved width
	return w;
}
void Solve() { //Determines each path X is able to make in the maze and compares to determine which is the shortest one.
	//After each step, the maze is added to the queue to determine next route and then the memory is deallocated 
	int r = 0;
	int c = 0;
	Maze[r][c] = 'X';
	Q = new Queue();
	Q->ENQUEUE(new QObj(r, c, Maze));
	
	while (!Q->EMPTY()) {
		QObj* currentM = Q->DEQUEUE();
		r = currentM->getr();
		c = currentM->getc();
		Maze = currentM->getM();
		if (r + 1 == h && c + 1 == w) {
			return;
		}
		if (r != 0) {
			if (Maze[r - 1][c] == ' ') {
				char** newMaze = new char* [h];
				for (int i = 0; i < h; i++) {
					newMaze[i] = new char[w];
					for (int j = 0; j < w; j++) {
						newMaze[i][j] = Maze[i][j];
					}
				}
				newMaze[r - 1][c] = 'X';
				Q->ENQUEUE(new QObj(r - 1, c, newMaze));
				delete[] newMaze;
			}
		}
		if (r != h - 1) {
			if (Maze[r + 1][c] == ' ') {
				char** newMaze = new char*[h];
				for (int i = 0; i < h; i++) {
					newMaze[i] = new char[w];
					for (int j = 0; j < w; j++) {
						newMaze[i][j] = Maze[i][j];
					}
				}
				newMaze[r + 1][c] = 'X'; 
				Q->ENQUEUE(new QObj(r + 1, c, newMaze));
				delete[] newMaze;
			}
		}
		if (c != 0) {
			if (Maze[r][c - 1] == ' ') {
				char** newMaze = new char*[h];
				for (int i = 0; i < h; i++) {
					newMaze[i] = new char[w];
					for (int j = 0; j < w; j++) {
						newMaze[i][j] = Maze[i][j];
					}
				}
				newMaze[r][c - 1] = 'X';
				Q->ENQUEUE(new QObj(r, c - 1, newMaze));
				delete[] newMaze;
			}
		}
		if (c != w - 1) {
			if (Maze[r][c + 1] == ' ') {
				char** newMaze = new char* [h];
				for (int i = 0; i < h; i++) {
					newMaze[i] = new char[w];
					for (int j = 0; j < w; j++) {
						newMaze[i][j] = Maze[i][j];
					}
				}
				newMaze[r][c + 1] = 'X';
				Q->ENQUEUE(new QObj(r, c + 1, newMaze));
				delete[] newMaze;
			}
		}
		delete currentM; 
	}
	delete Q;
	DisposeMaze();
}


