/* A simple program to show the basics of vectors:
     - Declaring them.
     - Checking their size
     - Resizing
     - Setting values;

   Written by Dr. Plank.  Original version is here:                                                  
   http://web.eecs.utk.edu/~jplank/plank/classes/cs140/Notes/SV-Basics/index.html     

 */

#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
  vector <int> v1;
  vector <double> v2(10);
  size_t i;

  /* Print out v1's size and v2's size.  It is unfortunate that size() returns
     an "size_t", which is an unsigned long, instead of an int, so you must use
     "%lu" instead of %d inside printf().  We'll talk about it in class.  */

  printf("V1's size: %lu.  V2's size: %lu\n", v1.size(), v2.size());

  /* Resize the vectors and print out the new sizes. */

  v1.resize(5);
  v2.resize(8);
  printf("V1's size: %lu.  V2's size: %lu\n", v1.size(), v2.size());

  /* Set the vectors' values, and print them out. */

  for (i = 0; i < v1.size(); i++) v1[i] = 10 + i;
  for (i = 0; i < v2.size(); i++) v2[i] = 20.3 + i;

  printf("V1:"); 
  for (i = 0; i < v1.size(); i++) printf(" %d", v1[i]); 
  printf("\n");

  printf("V2:"); 
  for (i = 0; i < v2.size(); i++) cout << " " << v2[i];
  cout << endl;

  return 0;
}
