#include <iostream>

// simple program to illustrate some of the fundamental types in C/C++

using namespace std;

int main() {

  char c;
  short i;

  int j;
  int a[10];

  long k;

  double d;

  cout << "Size of chars are " << sizeof (c) << " bytes." << endl;
  cout << "Size of shorts are " << sizeof (i) << " bytes." << endl;
  cout << "Size of ints are " << sizeof (j) << " bytes." << endl;
  cout << "Size of longs are " << sizeof (k) << " bytes." << endl;
  cout << "Size of doubles are " << sizeof (d) << " bytes." << endl << endl;

  cout << "Size of static array of 10 ints is: " << sizeof (a) << " bytes." << endl;
  
}
