/* This program reads three words at a time -- first name, last name, and social
   security number (as a string, not as a number).  It then prints them, each in
   its own column. 

Written by Dr. Plank, original version available here:                                                             http://web.eecs.utk.edu/~jplank/plank/classes/cs140/Notes/Output/index.html      

*/

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  string fn, ln, ssn;

  while (cin >> fn >> ln >> ssn) {
    printf("%-10s %-13s %11s\n", fn.c_str(), ln.c_str(), ssn.c_str());
  }
  return 0;
}
