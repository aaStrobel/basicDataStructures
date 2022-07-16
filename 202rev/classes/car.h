/*  Professor Scott, car.h

Interface (.h) file for our simple Car class today

Classes have both member functions (e.g., drive) and data members (e.g., transmission).
As we'll cover in class the data members are very similar to the encapsulation you did
in Fund I/C with structs, and the notation is very similar.  However, as we'll cover
the next two weeks including the functions in your objects will further help encapsulate,
generalize and extend your code to larger programs.

Lecture:  2/11/2021   */

#include <iostream>   

// Class Car
// This class interface models characteristics and functions of a car
// The drive function will drive the car automatically using other member
// functions such as gas, brake, start, etc.

class Car {

 public:

  void drive();     // run simulation!
  void brake();     // slow down
  void gas();      // speed up
  void upShift();   // shift up one gear
  void downShift(); // shift down one gear
  //Car();          // custom default constructor for initialization;
  // needs to be written in class or on your own, thus it is commented out

private:

  int color;         // color of car
  char model[100];   // model of car
  int transmission;  // tyoe of transmission
  int veryCool;      // coolness, on a scale of 1-10!

};

