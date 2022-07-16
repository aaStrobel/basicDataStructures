#include <iostream>

#include <set>

int main ()
{
  std::set<std::string> s;  // define a set of strings
  std::cout << "Adding 'Hello' and 'World' to the set twice" << std::endl;
  
  s.insert("Hello");  // insert values into set
  s.insert("World");
  s.insert("Hello");
  s.insert("World");

  // note:  the code below "destroys" the set; ideally we should copy
  // the set to a temporary variable.  We can use operator= to do this
  // as follows assuming t is defined:  t = s;
  
  std::cout << "Set contains:";
  while (!s.empty()) {      // while elements in the set
    std::cout << ' ' << *s.begin();
    s.erase(s.begin());
  }
  
  return 0;
}
