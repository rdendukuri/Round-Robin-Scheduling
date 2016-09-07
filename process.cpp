/*Name : Rahul Krishna Dendukuri
Z-ID : Z1749863
Course : CSCI 580-02
Program :process.cpp
Desciption : The source file for the constructor and methods of the Process class
Due Date : 10/12/2015
*********************************************************************/

#include "process.h"

/*Function : Process Constructor
Returns : void
*********************************************************************/

Process::Process()
{
        sub=0;
        CPUTimer=0;
        IOTimer=0;
        CPUTotal=0;
        IOTotal=0;
        CPUCount=0;
        IOCount=0;
	aTime=0;
	int i;
	for(i=0;i<12;i++)
		array[i]=0;
	ProcessName = "";

}
/********************************************************************
Function : terminate
Description : terminates a process
Paramenters : Process* P - pointer to the process to be pushed into the queue
	      int time - the termination Time stamp 	
Returns : void
*********************************************************************/

void Process::terminate(int time)
{
	cerr<<endl<<"Process : "<<ProcessID<<" Terminated\n----------\n";
	cerr<<"Process Name : "<<ProcessName<<endl;
	cerr<<"Arrival Time :"<<aTime<<endl;
	cerr<<"Ended at:"<<time<<endl;
	cerr<<"CPU Bursts = "<<CPUCount<<"\n";
	cerr<<"CPU time ="<<CPUTotal<<"\n";
	cerr<<"IO Bursts ="<<IOCount<<"\n";
	cerr<<"IO Time = "<<IOTotal<<"\n";
	int i=(time-aTime)-(CPUTotal+IOTotal);
	cerr<<"Waiting time ="<<i<<"\n";
	delete this;
}


