#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "Node.h"     // contains the node information
#include <iostream>   // for using cout

using namespace std;

template<typename T>    // templated class
class LinkedList {
 public:
  LinkedList();    // constructor
  ~LinkedList();   // deconstructor
  void appendNode(const T &);   // add a node to end of list
  bool empty();                 // if the list is empty
  int nodeCount();              // how many nodes are in the list

 private:
  Node<T> *first;                // first element in the list
  Node<T> * newNode(const T &);   // helper function; creates a new node
};

// constructor (empty body)
template<typename T>
LinkedList<T>::LinkedList() : first(NULL) {}

// destructor
template<typename T>
LinkedList<T>::~LinkedList() {
 if (!empty()) { // follow the links, clobbering as we go
  Node<T> *p= first;

  while (p != NULL) {
   Node<T> *next = p->next; // retrieve this node's "next" before we clobber it
   delete p;
   p = next;
   };
  }
 }

template<typename T>
void LinkedList<T>::appendNode(const T &data) {
 // allocate a new node, copying supplied data into it.
 Node<T> *nn  = newNode(data);

 if (empty()) { // make a new node
  first = nn;
  }
 else { // list already has nodes
  Node<T> *p = first;
  while (p->next != NULL) p = p->next; // go to end of list
  p->next = nn;
  }

 nn->next = NULL; // be safe
 }
 
// predicate: is this list empty?
template<typename T>
bool LinkedList<T>::empty() { return (first == NULL); }

// utility function to create a node
template<typename T>
Node<T> *LinkedList<T>::newNode(const T &value) {
 return new Node<T>(value);
 }

template<typename T>
int LinkedList<T>::nodeCount(void) {
 int n=0;
 for(Node<T> *p = first; p != NULL; p = p->next) n++;
 return n;
 }


#endif
