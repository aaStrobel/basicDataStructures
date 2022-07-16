#include <iostream>

// This is the finished version of what appears in the lecture fot the 6th video for spring 2020 CS140

using namespace std;

void helloWorld(const int &);
void helloWorld();

int main() {

  int years = 9;

  helloWorld(years);
  helloWorld();


}

// overloading prototypes

void helloWorld(const int &val) {

  cout << "Hello world!!!  Ryan is " << val << "years old" << endl;

  //  val = 10;                                                                                       

}

void helloWorld() {

  cout << "Hello world!!!" << endl;

}
