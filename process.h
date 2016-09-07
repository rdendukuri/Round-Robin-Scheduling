/*Name : Rahul Krishna Dendukuri
Z-ID : Z1749863
Course : CSCI 580-02
Program :Header File for  Assignment 4
Desciption : A Header file that contains the definition for the prcess class
Due Date : 10/12/2015
*********************************************************************/
#ifndef process_H
#define process_H

#include "Assign4.h"
class Process
{
  public:
        string ProcessName;
        int ProcessID;
        int array[ARRAY_SIZE];
        int sub;
        int CPUTimer;
        int IOTimer;
        int CPUTotal;
        int IOTotal;
        int CPUCount;
        int IOCount;
	int aTime;
  public:
	Process();
	void terminate(int time);

};
#endif

