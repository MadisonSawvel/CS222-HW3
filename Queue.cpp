
//Madison Sawvel

#include <iostream>
#include <string>
#include <cstdlib>
#include "Queue.h"
#include "LLN.h"
#include "QObj.h"
using namespace std;

Queue::Queue() { //constructor, sets head to null
	head = nullptr;
}

Queue::~Queue() { //deconstructor, deletes head to clean house
	delete head;
}

void Queue::ENQUEUE(QObj* obj) { //adds data to the queue
	if (!head) head = tail = new LLN(obj);
	else {
		tail->setnext(new LLN(obj));
		tail = tail->getnext();
	}
}

QObj* Queue::DEQUEUE() { //removes data from the queue and returns the object
	if (!head) return nullptr;
	QObj* obj = head->getinfo();
	LLN* t = head;
	head = head->getnext();
	t->setnext(nullptr);
	t->setinfo(nullptr);
	delete t;
	return obj;
}

bool Queue::EMPTY() { //returns whether the queue is empty as there is no head
	return !head;
}

