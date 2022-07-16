/*  Professor Scott. main.cpp

This code is largely based on another example in Chapter 9 (Section 9.2).

To compile this example, download the makefile and type make (as you have for
your pre/lab assignments.

The main examples here are that you can create arrays of objects (and the constructor
is run for each element) and set pointers to objects as you would have in C.  The
pointer thing is essential for the week after next, but since you all seem to 
understand the notation from lecture we'll cover pointers more in depth then.

*/

#include "time.h"  // include Time class definition

using namespace std;

int main () {

  Time my_time;                 // simple object
  Time my_time2;                // another simple objecy
  Time cool_array[10];          // array of objects, constructor run 10 times
  Time * time_ptr = &my_time;   // perfectly valid to use pointers

  my_time.setTime(14,12,30);  // set the time to 2:12 PM, 30 secs

  my_time.printStandard();  // print using standard
  time_ptr->printUniversal();  // use pointer to access object

  my_time2 = my_time;          // C++ give a default =; we will provide a
  my_time2.printStandard();    // non-standard copy constructor later

}
