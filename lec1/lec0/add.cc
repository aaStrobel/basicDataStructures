/*  Professor Scott, add.cc
    
    Simple program to ask for two numbers from a user, add them, and
    display the result

    additional material for First CS140 lecture : 1/21/21 */


#include <iostream>  // include header for i/o functions

int main () {

  int n;   // remember C++ variables are case-sensitive.  
  int second;   // second number

  std::cout << "Please enter first number: ";  // display message
  std::cin >> n;  // read in an int from stdin stream

  // NOTE:  ">>" is called stream extraction operator in c++
  //        given i/o is done via streams, this is why we include
  //        iostream as our predirective

  std::cout << "Please enter second number: ";  // display #2 message
  std::cin >> second;

  // similar to C, most operations are done relative to an assignment operator

  int sum = n + second;
  std::cout << "sum is = " << sum << std::endl;  // display result to user

}
