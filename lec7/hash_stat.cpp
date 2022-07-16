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
  int collisions = 0;

  while (getline(cin, line)) {

    h = bad_hash(line) % table_size;
    data[h].push_back (line);

    if (data[h].size() > 1)
      collisions++;

  }

  cout << collisions << endl;

}
