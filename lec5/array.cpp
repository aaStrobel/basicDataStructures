/* Professor Scott, array.cpp
1/27/2016

Implementation (.cpp) for Array class that we will cover in lecture today

*/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using std::cerr;
using std::cout;
using std::cin;
using std::endl;
using std::setw;

#include "array.h" // Array class definition

Array::Array( int arraySize )  {

  size = ( arraySize > 0 ? arraySize : 10 ); // validate arraySize

  ptr = new int[ size ]; // create space for pointer-based array

  for ( int i = 0; i < size; i++ )
    ptr[ i ] = 0; // set pointer-based array element to zero

} // end Array default constructor

Array::Array( const Array &arrayToCopy )  : size( arrayToCopy.size )  {

  ptr = new int[ size ]; // create space for pointer-based array

  for ( int i = 0; i < size; i++ )
    ptr[ i ] = arrayToCopy.ptr[ i ]; // copy into object

}  // end of copy constructor

Array::~Array() {

  delete [] ptr; // release pointer-based array space

} // end destructor

int Array::getSize() const  {

  return (size); // number of elements in Array

} // end function getSize

const Array &Array::operator=( const Array &right ) {

  if ( &right != this ) { // avoid self-assignment

    if ( size != right.size ) {
      
      delete [] ptr; // release space
      size = right.size; // resize this object
      ptr = new int[ size ]; // create space for array copy
    
    } // end inner if

    for ( int i = 0; i < size; i++ )	
      ptr[ i ] = right.ptr[ i ]; // copy array into object
  
  } 

  return (*this); // enables x = y = z, for example

} // end function operator=

bool Array::operator==( const Array &right ) const  {

  // arrays must have same # of elements to be equal
  if ( size != right.size )
    return false; 

  // all elements must be equal
  for ( int i = 0; i < size; i++ )
    if ( ptr[ i ] != right.ptr[ i ] )
      return false; 

  return (true); // Arrays are equal

} // end function operator==

istream &operator>>( istream &input, Array &a )
{

  for ( int i = 0; i < a.size; i++ )
    input >> a.ptr[ i ];
  
  return (input); // enables cin >> x >> y;

} // end function 

ostream &operator<<( ostream &output, const Array &a ) {

  for ( int i = 0; i < a.size; i++ ) {

    output << setw( 8 ) << a.ptr[ i ];

    if ( ( i + 1 ) % 4 == 0 ) // 4 numbers per row of output
      output << endl;
    
  } // end for

  output << endl;
  return (output); // enables cout << x << y;

} // end function operator<<
