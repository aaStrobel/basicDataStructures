#include <iostream>
using namespace std;

/* This sample code is a sample aggregate data type, initialization, and print/display in the C style

   We'll come back to this code when we introduce/talk about C++ classes in a week or two

  -----------  */

// aggregate data type in C/C++.  Sizeof should be sizes of all included variable types (here two ints)
struct coord {
  
  int x;
  int y;

};

coord initCoord (int newx, int newy);  // overloaded init functions, C-style
coord initCoord ();
void printCoord (const coord&);    // print function, C-Style using const


int main () {

  coord myCoord = initCoord (1, 10);  // since initCoord returns a coord, the assignment operator works here

  printCoord (myCoord);  // display initialized coordinate

}


coord initCoord () {

  coord entry;

  entry.x = 10;
  entry.y = 20;

  return (entry);

}

coord initCoord (int newx, int newy) {

  coord entry;

  entry.x = newx;
  entry.y = newy;

  return (entry);


}

void  printCoord (const coord &myC) {

  cout << myC.x << "  " << myC.y << endl;

  myC.x = 1000;

} 
