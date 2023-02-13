#ifndef _LIST_H_
#define _LIST_H_

#include <cstdio>
//start of Node class
class Node {
	public:
		Node();
		Node(char);
		char data;
		Node *next;
};
//end of Node class

//start of List class
class List {
	private:
		Node *head;
		Node *newNode(char);
		int count;
	public:
		void sumLists(List*, List*);
		List();
		~List();
		void addNode(char);
		int empty();
		int getCount();
		Node *getHead(); //returns head node
		void print(); //print list (output, I think) in the correct order
};
//end of List class
#endif


