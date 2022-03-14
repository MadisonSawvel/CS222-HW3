
//Madison Sawvel

#ifndef _QUEUE_
#define _QUEUE_
#include <iostream>
#include <string>
#include <cstdlib>
#include "LLN.h"
#include "QObj.h"

using namespace std;

class LLN;
class Queue {
private:
	LLN * head, * tail; //pointers to head and tail that cannot be changed
public:
	Queue(); //constructor, sets head to null
	~Queue(); //deconstructor, deletes head to clean house
	void ENQUEUE(QObj* obj); //adds data to the queue
	QObj* DEQUEUE(); //removes data from the queue and returns the object
	bool EMPTY(); //returns whether the queue is empty as there is no head
};

#endif
