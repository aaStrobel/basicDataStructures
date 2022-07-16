/* This is the same as ints1.cpp, except:

     - We print i and 2*i with a field width of two characters.
     - We print i*i with a field width of three characters.

   In that way, they all line up in nice, neat columns. 

Written by Dr. Plank, original version available here:                                                             
http://web.eecs.utk.edu/~jplank/plank/classes/cs140/Notes/Output/index.html      

*/

#include <cstdio>
using namespace std;

int main()
{
  int i, j;

  for (i = 0; i <= 10; i++) {
    j = i*i;
    printf("I is %2d - i*i is %3d - i*2 is %2d\n", i, j, i*2);
//               ^^^          ^^^          ^^^
  }
  return 0;
}
