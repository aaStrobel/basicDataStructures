/* This program contains code that I use all the time, to read a line on 
   standard input, and then to create a vector of all of the words on the line. 

Written by Dr. Plank, original version available here:                                                           
http://web.eecs.utk.edu/~jplank/plank/classes/cs140/Notes/Argv     

*/

#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
  string line;              // The line
  vector <string> sv;       // This holds the words on the current line
  int ln;                   // Line number
  size_t w;                 // Word number
  string s;                 // Helper
  istringstream ss;         // Helper

  ln = 0;

  /* Read the current line and update the line number. */

  while (getline(cin, line)) {
    ln++;

    /* Using a stringstream, create the vector of words on the line. */

    sv.clear();
    ss.clear();
    ss.str(line);
    while (ss >> s) sv.push_back(s);

    /* Print the line number, number of words, and the words. */

    printf("Line %d.  # Words: %lu:", ln, sv.size());
    for (w = 0; w < sv.size(); w++) printf(" %s", sv[w].c_str());
    printf("\n");
  }

  return 0;
}
