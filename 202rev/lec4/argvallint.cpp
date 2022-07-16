/* This reads all of the arguments on the command line to determine 
   whether each is an integer or not.  You have to call clear() on 
   the stringstream each time you set it to a new string.  

Written by Dr. Plank, original version available here:                                                           
http://web.eecs.utk.edu/~jplank/plank/classes/cs140/Notes/Argv     

*/

#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
  istringstream ss;
  int i, j;

  for (i = 1; i < argc; i++) {
    ss.clear();                      // Here is the clear command.
    ss.str(argv[i]);
    if (ss >> j) {
      printf("Argument %d -- %d\n", i, j);
    } else {
      printf("Argument %d -- %s is not an integer.\n", i, argv[i]);
    }
  }
  return 0;
}
