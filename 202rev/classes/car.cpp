/*  Professor Scott, car.cpp

Implementation (.cpp) file for our simple Car class today

Classes have both member functions (e.g., drive) and data members (e.g., transmission).

In your implementation file we will #include the interface (.h) file to define the class
and only implement the member functions (exceptions the next two weeks are static 
variables and friend functions)

Separating these files into separate files will be very helpful for your projects
and larger projects we will work on later in the semester.

Lecture:  2/11/2021   */

#include <iostream>
#include "car.h"           // include Car interface (.h)
using namespace std;


// member function drives the car
void Car::drive() {

  // vroom!!! vroomm!!!!

}

// member function slows down the car
void Car::brake() {

  // screeeetttchh!!!

}

// applies the gas
void Car::gas() {

  // faster!!! faster!!!

}

// changes gears
void Car::upShift() {

  transmission++;

}

// changes gears the other way
void Car::downShift() {

  transmission--;

}
