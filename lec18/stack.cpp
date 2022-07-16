/* Professor Scott, stack.cpp
2/9/15

Example of data hiding to implement a simple stack data structure

*/

#include <iostream>
#include <deque>

using namespace std;

template <typename T>
class MyStack {
public:
  void Add(T const &);   // add an element to queue
  void Remove();         // remove an element to queue
  void Print();          // display elements in queue
private:
  std::deque<T> data;   // is this good style?  why not?

};

template <typename T> 
void MyStack<T> ::Add(T const &d)
{
  data.push_back(d);  // add to the back of vector
}

template <typename T> 
void MyStack<T>::Remove()
{
     data.pop_back();
}

template <typename T> 
void MyStack<T>::Print()
{
  // display contents of vector using iterators
     
  for (int i = data.size()-1; i >= 0; i--) 
        cout << " " << data[i] << endl;

}
//Usage for C++ class templates
int main()
{
  MyStack<int> s;  // define a queue
  s.Add(1);     // add two values to queue
  s.Add(2); 

  cout<<"Before removing data"<<endl;
  s.Print();   // display values

  s.Remove();  // remove first value
  cout<<"After removing data"<<endl;
  s.Print();

}
