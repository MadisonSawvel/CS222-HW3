
//Madison Sawvel

#ifndef _QOBJ_
#define _QOBJ_
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class QObj {
private:
	int r, c; //makes row and column private so it can't be changed or accessed without including the file
	char** M; //creates pointer to pointer of M
public:
	QObj(int R, int C, char** MZ);  //constructor - sets the maze double array up using the size of row and column 
	~QObj(); //deconstructor, deletes the M object to clean house
	int getr(); //returns row value 
	int getc(); //returns column value
	char** getM(); //returns maze object
};
#endif