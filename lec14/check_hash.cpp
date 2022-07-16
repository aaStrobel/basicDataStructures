#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>

using namespace std;

// from Dr. Plank's lecture notes from hashing, most simple hash function you can think of
unsigned int bad_hash(const string &s)
{
  size_t i;
  unsigned int h = 0;
  
  for (i = 0; i < s.size(); i++) 
    h += s[i];
  
  return h;
}

int main() {

  string line;
  int table_size = 200000;
  vector<list<string> > data;
  data.resize(table_size);
  
  int h;

  while (getline(cin, line)) {

    h = bad_hash(line) % table_size;  // mod table size in the event hash value is too big
    data[h].push_back (line);

  }

  ifstream query;
  query.open("query.txt");

  std::list<string>::iterator it;

  while (getline(query, line)) {

    h = bad_hash(line);

    it = find (data[h].begin(), data[h].end(), line);  // same notation as a vector, same return
    if (it == data[h].end())
      cout << "Element not found in data from stdin" << endl;

  }

}
