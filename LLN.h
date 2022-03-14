
//Madison Sawvel

#ifndef _LLN_
#define _LLN_
#include <iostream>
#include <string>
#include <cstdlib>
#include "QObj.h"

using namespace std;

class QObj; 
class LLN {
private:
	QObj* info; //makes pointer object into private so it cannot be changed or accessed without including the file
	LLN* next; //creates pointer to next 
public:
	LLN(QObj* obj);  //constructor, sets object as  object info and makes next null
	~LLN(); //deconstructor, deletes the info and whatever is next to clean house
	LLN* getnext(); //returns the info of the object
	QObj* getinfo(); //sets the object to object info
	void setnext(LLN* n); //returns what is next 
	void setinfo(QObj* obj); //set next as n
};
#endif
