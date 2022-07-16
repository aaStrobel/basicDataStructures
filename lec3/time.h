#ifndef TIME_H
#define TIME_H

/*  Professor Scott. time.h

This code is largely based on another example in Chapter 9 (Section 9.2)

This class will store the time, defined in the constructor, and can display
the time in either a universal or standard form

Member functions are defined in time.cpp

NOTE:  the # statements above ensure the header file is including only
       once during compile time.  Required for larger assignments and projects

*/

// Class to store the (current) time

class Time {

 public:   // remember, public items go first!

  Time();                         // constructor for the class
  void setTime(int, int, int);    // set function: hour, min, sec
  void printUniversal();          // print version 1
  void printStandard();           // print version 2

 private:  // data will almost always be private to hide them from the client
  
  int hour;        // hour: 0-23
  int minute;      // minute: 0-59
  int second;      // second: 0-59

  // it is often prefered, not required, to specify ranges of data members
  // to aid debugging for other programers.

};

#endif
