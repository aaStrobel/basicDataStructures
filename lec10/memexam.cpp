#include <iostream>
#include <exception>
using namespace std;

int main () {
  //    try  // are you feeling lucky?
  //  {
      int* myarray= new int[10000000000000000];
      //     }
      /* catch (exception& e)  // catch block, base class exception
	  {
      cout << "Standard exception: " << e.what() << endl;
      }*/

  // see if the catch block worked
  cout << "made it safe (sort of!)" << endl;

  return 0;
}
