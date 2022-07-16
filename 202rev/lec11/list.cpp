#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct node {

  int data;
  node * next;

};



int main() {

  node * head = NULL;

  head = new node();

  vector<int> v;

  head->data = 1;
  head->next = NULL;

  node * newNode;
  
  for (int i = 2; i < 10; i++) {
  
    newNode = new node();

    newNode->data = i;
    newNode->next = head;
    head = newNode;

  }
  
  // 1
  // 2 1
  // 3 2 1
  // 4 3 2 1


  node * ptr = head;

  while (ptr != NULL) {

    cout << ptr->data << endl;
    ptr = ptr=>next;

  }
				
