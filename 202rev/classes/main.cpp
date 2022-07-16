/*  Professor Scott, main.cpp

Main function (.cpp) file for our simple Car class today

Becuase the class has all of the functions (e.g., drive) and data (e.g., transmission) 
your main function, also called a client in the text, will often be very short.

Note, though, you must instantiate/create an object (like myCar below) in order to be
able to use these functions.  This is why C++ is called an object-oriented language.

Lecture:  2/11/2021   */

#include <iostream>   
#include <string>
#include "car.h"

int main() {

  Car myCar;  // instantiate car object
  myCar.drive();   // run function

  return (0);   // return 0 as the program ended successfully

}
