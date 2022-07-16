#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {

  string line;
  vector<string> data;
  ifstream query;

  // read in names from stdin, one per line and put into vector
  while (getline(cin, line)) {

      data.push_back(line);

  }

  // names to search in our data structure
  query.open("query.txt");

  std::vector<string>::iterator it;

  while (getline(query, line)) {

    it = find (data.begin(), data.end(), line);
    if (it == data.end())  // if STL iterator equals end, it is not found!
      cout << "Element not found in data from stdin" << endl;

  }

}
