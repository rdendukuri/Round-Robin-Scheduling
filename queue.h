/*Name : Rahul Krishna Dendukuri
Z-ID : Z1749863
Course : CSCI 580-02
Program :Header File for  Assignment 4
Desciption : A Header file that contains the definition for the queue class
Due Date : 09/23/2015
*********************************************************************/

#ifndef queue_H
#define queue_H

#include "process.h"

class Queue 
{
   public:
	Process *pq[QUEUE_SIZE];
	int top;
	int bottom;
	int count;
	Queue();
	void push(Process* & p);
	Process* pop();
	void printQ();
};

#endif
