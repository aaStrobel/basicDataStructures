#include <iostream>
#include <map>
using namespace std;

int main() {

  // Goal:  Determine unique words in a file and their
  // counts

  string value;
  map<string, int> myMap;   // map where key,value is string and int

  while (cin >> value) {

    cin >> value;

    myMap[value]++;  // note operator[] works; if value is not in the map
                     // this version of the compiler initializes it to zero
  }

  //  cout << myMap.count() << endl;
  cout << myMap.size() << endl;

}
