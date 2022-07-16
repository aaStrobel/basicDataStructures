#include <iostream>
using namespace std;

/* - Use cin to read single characters.
   - Count the total number of characters.
   - Count the number of L's. 

Written by Dr. Plank and available from:
http://web.eecs.utk.edu/~jplank/plank/classes/cs140/Notes/Review/index.html 

*/

int main() {

  int numChars = 0;      // Total number of characters
  int numLs = 0;      // Total number of L's
  char c;

  while (cin >> c) {
    numChars++;
    if (c == 'L') numLs++;
  }

  cout << "# of characters: " << numChars << endl;
  cout << "# of L's: " << numLs << endl;
  return 0;

}
