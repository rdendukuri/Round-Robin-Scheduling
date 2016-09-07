# Round-Robin-Scheduling

Usage:
 
  $ make all
  $ ./Assign4 data.txt


We are simulating Round-Robin scheduling of processes on a single-processor system using time slices.

The assumptions are as follows:

(a) We will assume the processes alternate between CPU bursts and I/O 
    bursts, ignoring other interrupts.  

(b) We will assume that all processes are doing I/O through the same 
    device which can process one I/O burst at a time.  

(c) We will assume the system starts out with no processes active but  
    with a number of them already waiting in an input queue.

(d) The array called Array (described below) is a convenience.  (an    
    alternative would be to generate the data dynamically using 
    random numbers.)

The events are governed by a timer which is simply counting clock 
ticks.  (For our purposes, a clock tick might be one or two milliseconds.)



We have a class to represent one process.  The items stored on the queues are pointers to processes.  
The program requires 3 queues:  Entry, Ready and IO.  We will also have variables Active and IOActive (pointers to processes).  

---------------------------------------------------------------------

The constants are defined below:
Assign4.h
MAX_TIME is an integer = length of the whole run. I used the value 500.

TIME_SLICE is an integer = maximum time before a process is cycled out to the Ready Queue.  Use the value 5.

IN_USE is an integer = maximum number of processes that can be in play at once (that is, not still in the Entry Queue).  Use the value 5.

QUEUE_SIZE is an integer guaranteed larger than the maximum number of 
items any queue will ever hold.  Use the value 20.

ARRAY_SIZE is an integer = size of the array to define in a process.  
Use the value 12.

HOW_OFTEN is an integer indicating how often to reprint the state of 
the system.

---------------------------------------------------------------------


Array is an array of integers:  positive values = length of a CPU burst; negative values = -1 * length of an I/O burst; and 0 indicates the process is done.  We guarantee no two consecutive positive or negative values.  The first entry is always positive.

Sub is a subscript into the array Array.

CPUTimer counts clock ticks for the process until it reaches 
TIME_SLICE or the end of the CPU burst.

IOTimer counts clock ticks for the process until it reaches the end of the I/O burst.

CPUTotal accumulates the number of clock ticks the process spends as 
Active.

IOTotal accumulates the number of clock ticks the process spends as 
IOActive.

CPUCount counts the CPU bursts for this process.

IOCount counts the I/O bursts for this process.

---------------------------------------------------------------------

Input file:
data.txt
Each line in the input file describes one process.  It contains:

--- a string = the name of this process

--- a sequence of integers as described above, separated by spaces

The last line has process name = "STOPHERE" and should not be 
included.  It simply serves as a delimiter.


---------------------------------------------------------------------

What should happen?

The structure of the program is that a process moves from the Input 
queue to the Ready queue, eventually becomes Active, is moved to the 
IO queue or back to the Ready queue as appropriate, and eventually terminates.  We will accumulate various statistics about each process and some global statistics about the run as a whole.  

1.  Read the input file.  Create processes and push them onto the
Entry Input Queue.

2.  Pop some of the processes off the Entry Queue and push them onto
the Ready Queue.  

3.  We have a main loop.  It starts with Timer = 0.  Timer is incremented at the bottom of the loop, and the loop ends when Timer reaches MAX_TIME or there are no processes left (all queues empty, Active and IOActive both 0).

At this point, you need to decide what to do in each case:

If we do not have an Active process, we need to look for one.

If we still do not have an Active process, there is little to 
do on this iteration of the loop.

If we do have an Active process, what could happen to it?

--- It could come to the end of a CPU burst which is followed by an 
    I/O burst.

--- It could come to the end of a CPU burst which is followed by 
    termination of the process.

--- It could come to the end of a time slice but not yet the 
    end of a CPU burst.

If we do not have an IOActive process, we need to look for one.

If we have an IOActive process, it may come to the end of its 
I/O burst.

4.  After the main loop, print summary data about the whole run, such as these (you may think of more):

--- What was the value of the Timer at the end?

--- How many processes terminated normally?

--- What was left in each queue at the end?

--- How much time was spent doing nothing (idle time)?

This description leaves out a few details, such as initializing the
variables.  You may in fact need a few more variables.  You will need
a Terminate() function and perhaps more.

As the program runs, print output about major events such as when a 
process enters the cycle from the Entry queue or when a process
terminates.  When a process terminates, print what we know about it, such as:

--- how many CPU bursts occurred
--- how many I/O bursts occurred 
--- how much time was spent in the CPU
--- how much time was spent in I/O
--- how much time was spent in waiting

Whenever the timer is a multiple of HOWOFTEN, print out the state of the system:

--- the ID number of the Active process (if there is one) 
--- the ID number of the IOActive process (if there is one)
--- the contents of the Ready and IO queues


---------------------------------------------------------------------


