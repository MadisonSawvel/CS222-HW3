
//Madison Sawvel

#include <iostream>
#include <string>
#include <cstdlib>
#include "QObj.h"
#include "LLN.h"

using namespace std;

LLN::LLN(QObj* obj) { //constructor, sets object as  object info and makes next null
	info = obj;
	next = nullptr;
}
LLN::~LLN() { //deconstructor, deletes the info and whatever is next to clean house
	delete info;
	delete next;
}
QObj* LLN::getinfo() { //returns the info of the object
	return info;
}
void LLN::setinfo(QObj* obj) { //sets the object to object info
	info = obj;
}
LLN* LLN::getnext() { //returns what is next  
	return next;
}
void LLN::setnext(LLN* n) { //set next as n
	next = n;
}