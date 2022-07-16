/* This program shows some subtleties of resizing vectors. */

// Written by Dr. Plank.  Original version is here:                                             
// http://web.eecs.utk.edu/~jplank/plank/classes/cs140/Notes/SV-Basics/index.html     

#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  vector <int> v1;
  size_t i;

  /* Start with two v1.resizes, setting new elements to 22 and 33. */

  v1.resize(5, 22);
  v1.resize(8, 33);

  printf("Initial V1:            ");
  for (i = 0; i < v1.size(); i++) printf(" %d", v1[i]); 
  printf("\n");

  /* Chop it down to six elements. */

  v1.resize(6);
  printf("v1.resize(6):          ");
  for (i = 0; i < v1.size(); i++) printf(" %d", v1[i]); 
  printf("\n");

  /* Now resize to 10 elements, setting the new ones to 44. */

  v1.resize(10, 44);
  printf("v1.resize(10, 44):     ");
  for (i = 0; i < v1.size(); i++) printf(" %d", v1[i]); 
  printf("\n");

  /* Does this add 5 new random elements, or 5 copies of one random element? */

  cout << RAND_MAX << endl;

  v1.resize(15, rand());
  printf("v1.resize(15, rand()): ");
  for (i = 0; i < v1.size(); i++) printf(" %d", v1[i]); 
  printf("\n");

  return 0;
}
