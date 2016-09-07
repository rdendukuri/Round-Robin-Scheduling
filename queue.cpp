/*******************************************************************
Name : Rahul Krishna Dendukuri
Z-ID : Z1749863
Course : CSCI 580-02
Program :Header File for  Assignment 4
Desciption : source file that contains the constructor and methods of Queue class
Due Date : 10/12/2015
*********************************************************************/

#include "queue.h"
/********************************************************************
Function : Queue constructor 
Description : Initializes the contents of the queue class
Paramenters : void
Returns : void
*********************************************************************/

Queue::Queue()
{
        top=-1;
        bottom=-1;
	count = 0;
	int i;
	for(i=0;i<QUEUE_SIZE;i++)
		pq[i]=0;
}
/********************************************************************
Function : Push
Description : Pushes a process into the queue
Paramenters : Process* P - pointer to the process to be pushed into the queue 
Returns : void
*********************************************************************/

void Queue::push(Process* & p)
{
	int i;

	if(!((top==QUEUE_SIZE-1)&& bottom==0))
	{
		if((top==QUEUE_SIZE-1)&& (bottom == QUEUE_SIZE-1))
		{
			bottom=0;
			pq[bottom]=pq[top];
			top=-1;
		}
		else if(top==QUEUE_SIZE-1)
		{
			int j=bottom;
			for(i=0;i<count;i++)
			{
				pq[i]=pq[j++];
			}
			bottom=0;
			top=count-1;

		}
		pq[++top]=p;
		if(bottom==-1)
			(bottom)++;
		count++;
	}
	else
		fprintf(stderr,"Queue is full\n");


 	
}
/********************************************************************
Function : pop
Description : Pop a process from the queue and returns a pointer to the process removed
Paramenters : void
Returns : Process*
*********************************************************************/

 Process* Queue::pop()
{
	
	Process* t;

	if(bottom!=-1)
	{
		if(top==bottom)
			{
				t=pq[bottom];
				top=-1;
				bottom=-1;

			}
		else
			t=pq[bottom++];
		this->count--;

	}
	else
		fprintf(stderr,"Queue is Empty\n");		
	
	return t;


}
/********************************************************************
Function : printQ
Description : Prints the contents of a queue
Paramenters : void
Returns : void
*********************************************************************/

void Queue::printQ()
{
	int i=1;
	int j;
	if(top==-1 && bottom==-1)
	{
		cerr<<"Queue Empty\n";
		return;
	}
	for(i=bottom;i<=top;i++)
	{
		cerr<<"process ID : "<<(pq[i])->ProcessID<<"\n";
	}


}
