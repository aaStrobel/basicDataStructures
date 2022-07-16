/*  Professor Scott. prob9.11.h

This code is largely based on the example in class relating to a rectangle from 
a previous version of text than some of you may have.  The functions were 
completed in class

*/

#include <iostream>
using namespace std;


// class definition for a rectangle class

class Rectangle {

public:

  Rectangle ();              // constructor
  void setLength(float);     // set/mutator functions
  void setWidth(float);
  float getLength();         // get/accessor functions
  float getWidth();  
  float area();              // compute and return area
  float perimeter();         // compute and return perimeter

private:

  float length;       // length of rectangle
  float width;        // width of rectangle

};
