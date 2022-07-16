/* Use printf() to print out each number, i, from 0 to 10,
   along with its square and its double. 

Written by Dr. Plank, original version available here:
http://web.eecs.utk.edu/~jplank/plank/classes/cs140/Notes/Output/index.html

*/

#include <cstdio> // ****
using namespace std;

int main()
{
  int i, j;

   for (i = 0; i <= 10; i++) {
     j = i*i;
     //****
     printf("I is %d - i*i is %d - i*2 is %d\n", i, j, i*2);
   }
   return 0;
}
