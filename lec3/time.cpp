/*  Professor Scott. time.cpp

This code is largely based on the example in Chapter 9 (Section 9.2)

Member functions are defined in this file : time.cpp

*/

#include <iostream>
#include <iomanip>
#include "time.h"   // include class definition defined in time.h

using namespace std;


// Time constructor initializes each data member to zero
// NOTE:  constructors are ALWAYS run once, to ensure a consistent state
// when first declared/instantiated.

Time::Time() {

  hour = minute = second = 0;  

}

// set new Time value using universal time
void Time::setTime(int h, int m, int s) {

  // the below does no validation of the hour, minute and second, which isn't optimal
  // Figure 9.2 has an if statement to check this, but we prefer in an OOP manner to
  // have a setHour, setMinute, and setSecond such that these functions could be used
  // later if needed

  hour = h;     
  minute = m;   
  second = s;

}

// print time in universal-time format (HH:MM:SS)
void Time::printUniversal() { 

  // it is possible to modify the stream operators (like cout) for
  // pretty displays.  We will not cover these today, but they exist if
  // you are curious.  Sort of like printf ("%0.2d", my_int) in C
  // see full example in Chapter 9

  cout << setfill('0') << setw(2) << hour << ":" <<
    setw(2) << minute << ":" << setw(2) << second << endl;

}

//print Time in standard-time formmat (w/ AM or PM)
void Time::printStandard() {

  // NOTE:  even though printStandard is a public function, it can
  // view (and change) private data.  C-style expressions like the
  // ? if then are accepted (and sometimes convienient) in C++

  cout << ( (hour == 0 || hour == 12) ? 12 : hour % 12) << ":" <<
    setfill('0') << setw(2) << minute << ":" << setw(2) << second 
       << (hour < 12 ? " AM" : " PM") << endl;

}
