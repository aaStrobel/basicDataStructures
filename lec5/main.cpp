// Fig. 11.8: fig11_08.cpp
// Array class test program.

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "array.h"

int main() {

  Array integers1( 7 ); // seven-element Array   
  Array integers2; // 10-element Array by default

  cout << "Size of Array integers1 is " 
       << integers1.getSize() << endl;

  cout << "\nSize of Array integers2 is " 
       << integers2.getSize() << endl;

  cout << "\nEnter 12 integers:" << endl;
  cin >> integers1 >> integers2;

  cout << "Array 1 " << integers1 << endl;

  cout << "Array 2 " << integers2 << endl;

}  // end of main
