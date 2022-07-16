/* Professor Scott, this.cpp

Simple toy example illustrating uses of the this pointer

*/

#include <iostream>

using namespace std;

// class definition
class SimpleClass {

public:
  SimpleClass () : myVal(0) {};  // default constructor, inlined as an example
  void print();  // simple print function
  void setValue();

private:

  int myVal;  // simple integer

};

Foo SimpleClass:: print() {

  cout << myVal << endl;           // all of these are equivalent
  
  cout << this->myVal << endl;
  cout << (*this).myVal << endl;

  return (*this);

}

int main() {

  SimpleClass Foo;    // create an object

  Foo.print().print();  // call member function
  // >>> Foo.print

  vector<int> v;
  v.push_back(1);

  c.at(i).foo().()

}
