/* Print pi, e, and the natual log of 10, each with 7 total digits, 5 after the decimal point. 

Written by Dr. Plank, original version available here:                                                             http://web.eecs.utk.edu/~jplank/plank/classes/cs140/Notes/Output/index.html      

*/

#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
  double pi, e, ln10;

  pi   = acos(-1.0);  // I figure at this point, you might enjoy some high school math.
  e    = exp(1.0);    // exp(x) returns e to the x-th power
  ln10 = log(10.0);   // The poorly named log(x) returns the natural log of x.

  printf("pi:   %7.5lf\n", pi);
  printf("e:    %7.5lf\n", e);
  printf("ln10: %7.5lf\n", ln10);

  return 0;
}
