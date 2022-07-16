/* This program uses a stringstream to convert the first command line
   argument to an integer.  It prints an error if it is not an integer. 

Written by Dr. Plank, original version available here:                                                           http://web.eecs.utk.edu/~jplank/plank/classes/cs140/Notes/Argv     

*/

#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
  istringstream ss;
  int i;

  /* Make sure there is exactly one command line argument. */

  if (argc != 2) { 
    cerr << "usage: argv1int argument\n"; 
    return 1; 
  }

  /* Use the stringstream to convert the argument to an integer, or print
     an error on standard error. */

  ss.str(argv[1]);
  if (ss >> i) {
    printf("Integer: %d\n", i);
  } else {
    fprintf(stderr, "The argument %s is not an integer.\n", argv[1]);
    return 1;
  } 

  return 0;
}
