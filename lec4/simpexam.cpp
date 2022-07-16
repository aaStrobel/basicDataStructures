#include <iostream>
using namespace std;

int main () {
  try  //try block
    {
      throw 20;
    }
  catch (int e)  // catch 20, print 20
    {
      cout << "An exception occurred. Exception Nr. " << e << '\n';
    }
  return 0;

}
