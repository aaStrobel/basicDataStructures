/* This program introduces you to argc and argv.  They are parameters to main(), and
   tell you the number of words on the command line, and what those words are.  Note
   that argc is always at least one, and argv[0] is usually the name of the program. 

Written by Dr. Plank, original version available here:
http://web.eecs.utk.edu/~jplank/plank/classes/cs140/Notes/Argv

*/

#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char **argv)
{
  int i;
  string s;

  /* Print argc. */

  printf("Argc is %d\n", argc);
  printf("\n");

  /* Print argv using printf() and c-style strings. */

  for (i = 0; i < argc; i++) {
    printf("argv[%d] = %s\n", i, argv[i]);
  }
  printf("\n");

  /* Print argv by copying each argument to a C++ string and printing it with cout. */

  for (i = 0; i < argc; i++) {
    s = argv[i]; // turn C string argv[1] into c++ string s 
    cout << "argv[" << i << "] = " << s << endl;
  }
  return 0;
}
