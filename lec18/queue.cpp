/* Professor Scott, queue.cpp
2/9/15

Example of data hiding to implement a simple queue data structure

*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MyQueue {
public:
  void Add(T const &);   // add an element to queue
  void Remove();    // remove an element to queue
  void Print();  // display elements in queue
private:
  vector<T> data;   // we'll use a vector as our underlying data structure here

};

template <typename T> 
void MyQueue<T> ::Add(T const &d)
{
  data.push_back(d);  // add to the back of vector
}

template <typename T> 
void MyQueue<T>::Remove()
{
     data.erase(data.begin( ),data.begin( ) + 1);
     // first item is removed
}

template <typename T> 
void MyQueue<T>::Print()
{
  // display contents of vector using iterators
  typename std::vector <T>::iterator It1;
     It1 = data.begin();
     for ( It1 = data.begin( ) ; It1 != data.end( ) ; It1++ )
        cout << " " << *It1 << endl;

}
//Usage for C++ class templates
int main()
{
  MyQueue<int> q;  // define a queue
  q.Add(1);     // add two values to queue
  q.Add(2); 

  cout<<"Before removing data"<<endl;
  q.Print();   // display values

  q.Remove();  // remove first value
  cout<<"After removing data"<<endl;
  q.Print();
}
