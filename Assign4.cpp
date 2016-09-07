/*******************************************************************
Name : Rahul Krishna Dendukuri                          FALL 2015
Z-ID : Z1749863
Course : CSCI 580-02
Instructor : Harry Hutchins
TA : Sweta Thota
Program : Assignment 4
Desciption : A C++ program that simulates the Round Robin CPU Scheduling
Due Date : 10/12/2015
*********************************************************************/

#include "Assign4.h"
#include "process.h"
#include "queue.h"
int sumA(Process* p);
int sumB(Process* p);
Queue Entry,IO,Ready;

/*
Function : Main
Paramenters : int argc - No. of command line arguments
	      char **argv-Array of pointers for the the command line arguments	
Returns : int
*********************************************************************/
int main(int argc,char **argv)
{
         if (argc!=2)//Checking if right number of command line arguments have been entered while executing the program
                {

                cerr<<"usage:_"<<argv[0]<<"_inputFile\n"; //Printing out the error message with correct usage of the Program
                return 0;
                }


	 ifstream In;
	 Process* P;
	 int i;
	 int k=1;
	 string ProcName;
	 In.open(argv[1]);
	 In >> ProcName;
	 while (ProcName != "STOPHERE")
 	 {//Loading untill STOPHERE is reached in the file
		P = new Process;
		P->ProcessName = ProcName;
		P->ProcessID = 100+k;
	        for (i = 0; i < ARRAY_SIZE; i++)
	        In >> P->array[i];
	        Entry.push(P);
	        In >> ProcName;
	  	k++;
 	 }
	In.close();
        Process* Active=0;
        Process* IOActive=0;
        Process* p1;
        int time=0;
	int idle=0;
	int proc_terminated=0;
        for(k=0;k<=IN_USE;k++)
	{//Loading the initial processes into Ready Queue
		p1=Entry.pop();
                p1->aTime=time;
		Ready.push(p1);
		cerr<<endl<<"Process pushed to Ready Queue: "<<p1->ProcessID<<"\n"<<endl;


        }
     
        Active = Ready.pop();
        while(time<MAX_TIME)
        {//The Scheduling loop 
			
		
		if(Active==0 && Ready.count>0)
		{//Loading process from ready queue into the Active pointer
                	Active=Ready.pop();
				
			
		}
				
		if(Active==0)
			idle++;//incrementing idletime when we have no active process
			


                if(IOActive==0 && IO.count>0)
		{//Loading a process ready for IO into the IOActive pointer
                	IOActive=IO.pop();
				 
		}
		if(time%HOW_OFTEN==0)
		{//The HOW_OFTEN summary
			cerr<<endl<<"Time stamp now :"<<time<<endl;
			if(Active!=0)
				cerr<<"The PID of the Active process: "<<Active->ProcessID<<"\n";
			else
				cerr<<"No Active process: The CPU is idle\n";
		        if(IOActive!=0)
                       	        cerr<<"The PID of the IOActive process: "<<IOActive->ProcessID<<"\n";
                        else
                                cerr<<"No IOActive process\n";
			cerr<<"Ready Queue Contents-------\n";
			Ready.printQ();
			cerr<<"IO Queue Contents-------\n";
			IO.printQ();
			cerr<<endl;
		}	
                if(Active!=0)
                {

                	if(Active->array[Active->sub]!=0)
			{//Incrementing CPU parameters as a part of a CPU burst

                        	Active->CPUTimer++;
                                Active->CPUTotal++;
                        }
                              

                        if((Active->CPUTotal)==sumA(Active))
                        {//checking for end of the CPU burst

                                Active->sub=Active->sub+1;

                        }
                                
                                
                        if(Active->array[Active->sub]<0)
                        {//If the CPU burst did end

                           	Active->CPUTimer=0;
	                        Active->CPUCount++;
        	                IO.push(Active);
                	        Active=0;

                        }
                        else if(Active->CPUTimer%TIME_SLICE==0 && ( Active->array[Active->sub]!=0))
                        {//Else if the CPU time slice of the process has ended

				Active->CPUTimer=0;
        	                Ready.push(Active);
                	        Active = 0;

                        }

                                

                 }
			
                 if(IOActive!=0)
                 {

                             	if(IOActive->array[IOActive->sub]!=0)
                                 {//Incrementing IO parameters as a part of a IO burst
			
                         	 	IOActive->IOTimer++;
                                        IOActive->IOTotal++;
                                 }

	                        if((IOActive->IOTotal)+sumB(IOActive)==0)
                                 {//checking for end of an IO burst
						
                                        IOActive->sub=IOActive->sub+1;
                                 }

                                if(IOActive->array[IOActive->sub]>0)
                                { //If the IO burst did end,the process is pushed into ready queue
			
                               
                                        IOActive->IOTimer=0;
                                        IOActive->IOCount++;
                                        Ready.push(IOActive);
                                        IOActive=0;
                                }
                 }

		if(Active!=0)
		{
				if(Active->array[Active->sub]==0)
                                {//cheking for termination

					if(Active->IOTotal+sumB(Active)==0)//Seeing if the IO is also complete
					{
                                       	
						Active->CPUCount++;
	                                        Active->terminate(time);
						proc_terminated++;
        	                                if(Entry.count>0)
                	                        {
                                                	p1=Entry.pop();
	                                                p1->aTime=time;
        	                                        Ready.push(p1);
							cerr<<"Process pushed to Ready Queue"<<p1->ProcessID<<"\n"<<endl;
	
                        	                }
					}
                                      
                                
					Active = 0;
						
                                }
		}
		if(IO.count==0 && Ready.count==0 && Entry.count==0 && Active==0 && IOActive==0 )//breaking for the scheduling loop if everything is done
                	break;


			time++;
                        }
//Printing out the details of the run
		cerr<<endl<<"The run has ended."<<endl;
		cerr<<"The final value of the timer was:"<<time<<endl;
		cerr<<"The amount of time spent idle was:"<<idle<<endl;
		cerr<<"Number of terminated processes ="<<proc_terminated<<endl;
		cerr<<"Contents of the Entry Queue:"<<endl;
		Entry.printQ();
		cerr<<"Contents of the Ready Queue:"<<endl;
		Ready.printQ();
		cerr<<"Contents of the IO Queue:"<<endl;
		IO.printQ();
		cerr<<endl;


		return 0;
}

/*
Function : SumA
Paramenters : Process* P - The process pointer for whom the CPU burst is calculated
Returns : int
*********************************************************************/

int sumA(Process* p)
{
	int i=0;
	int sum=0;
	while(i<=p->sub)
	{
		sum=sum+p->array[i];
		i=i+2;
	}
	return sum;
}

/*
Function : SumB
Paramenters : Process* P - The process pointer for whom the IO burst is calculated
Returns : int
*********************************************************************/

int sumB(Process* p)
{
        int i=1;
        int sum=0;
        while(i<=p->sub)
        {
                sum=sum+p->array[i];
                i=i+2;
        }
        return sum;
}

