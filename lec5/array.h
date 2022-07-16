/* Professor Scott, array.h
1/27/2016

Example for the lecture notes and for class on overloaded operators for arrays

*/

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using std::ostream;
using std::istream;

// Array class definition
class Array {

  friend ostream &operator<<( ostream &, const Array & );  // output
  friend istream &operator>>( istream &, Array & );       // input

 public:

  Array( int = 10 ); // default constructor  
  Array( const Array & ); // copy constructor
  ~Array(); // destructor                    

  int getSize() const; // return size

  const Array &operator=( const Array & ); // assignment operator
  bool operator==( const Array & ) const; // equality operator   

  bool operator!=( const Array &right ) const {                                                     
    return ! ( *this == right ); // invokes Array::operator==

  } // end function operator!=                                

 private:
  
  int size; // pointer-based array size
  int *ptr; // pointer to first element of pointer-based array

}; // end class Array

#endif


