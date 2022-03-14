
//Madison Sawvel

#include <iostream>
#include <string>
#include <cstdlib>
#include "QObj.h"
#include "PG3.h"

using namespace std;

QObj::QObj(int R, int C, char** MZ) { //constructor - sets the maze double array up using the size of row and column 
	r = R;
	c = C;
	M = new char* [height()];
	for (int i = 0; i < height(); i++) {
		M[i] = new char[width()];
		for (int j = 0; j < width(); j++)
			M[i][j] = MZ[i][j];
	}
}
QObj::~QObj() { //deconstructor, deletes the M object to clean house
	for (int i = 0; i < height(); i++)
		delete M[i];
	delete M;
}
int QObj::getr() { //returns row value
	return r;
}
int QObj::getc() { //returns column value
	return c;
}
char** QObj::getM() { //returns maze object
	return M; 
}