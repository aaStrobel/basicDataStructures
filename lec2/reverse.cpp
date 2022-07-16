/* This program uses a vector to print standard input in reverse order. */

// Written by Dr. Plank.  Original version is here:                                                      
// http://web.eecs.utk.edu/~jplank/plank/classes/cs140/Notes/SV-Basics/index.html     

#include <vector>
#include <iostream>
using namespace std;

int main()
{
  vector <string> lines;
  int i;
  string s;

  /* Read every line of standard input into a vector called lines. */

  while (getline(cin, s)) {

    lines.push_back(s); // ******

  }

  /* Now print lines in reverse order. */

    for (i = lines.size()-1; i >= 0; i--)   
    cout << lines[i] << endl;

  return 0;
}
