/*
 #include <cstdio>
 28
 29 //start of Node class
 30 class Node {
 31     public:
 32         Node(int);
 33         int data;
 34         Node *next;
 35 };
 36 //end of Node class
 37
 38 //start of List class
 39 class List {
 40     private:
 41         Node *head;
 42         Node *newNode(int);
 43         int count;
 44     public:
			List sumLists(List, List);
 45         List();
 46         ~List();
 47         void addNode(int);
 48         int empty();
 49         int getCount();
 50         Node *getHead(); //returns head node
 51         void print(); //print list (output, I think) in the correct order
 52 };
 53 //end of List class
*/

#include "list.h"
#include <string>
#include <iostream>

Node::Node(){
	next = NULL;
}

//start of Node functions
Node::Node(char c) {
	data = c;
	next = NULL;
}
//end of Node functions

//start of List functions
List::List() {
	head = NULL;
	count = 0;
}

//copied Dr. Emrich's function
List::~List() {
	if (!empty()) { // follow the links, clobbering as we go
		Node *p = head;

		while (p != NULL) {
			Node *next = p->next; // retrieve this node's "next" before we clobber it
			delete p;
			p = next;
		}
	}
}

void List::sumLists(List *list1, List *list2) {
    char carry = 0, sum, char1, char2;
	Node* currentPtr1 = list1->head, *currentPtr2 = list2->head;
    while (1){
         if (currentPtr1 == NULL && currentPtr2 == NULL){ 
			 if (carry != 0) this->addNode(carry + '0');	 
			 break;
		 } 
         if (currentPtr1 != NULL){
             char1 = currentPtr1->data;
             currentPtr1 = currentPtr1->next;
         } else {
             char1 = '0';
         }
         if (currentPtr2 != NULL){
             char2 = currentPtr2->data;
             currentPtr2 = currentPtr2->next;
         } else {
             char2 = '0';
         }

		 char1 -= '0';
		 char2 -= '0';
         sum = char1 + char2 + carry;
         carry = sum / 10; //returns 1 at most (or just 0)
         sum %= 10; // will return 0 to 8
         sum += '0'; //is 48 in decimal
         this->addNode(sum);
     }

     //-iterate through lists starting at the head node
     //-adding values each iteration and checking for carry
     //-handle lists of different sizes
}


//helper function to create a new node
Node *List::newNode(char c) {
	Node *node = new Node(c);
	node->next = NULL;
	return node;
}

//copied Dr. Emrich's function
void List::addNode(char c) {
	Node *node = newNode(c);
	node->next = head;
	head = node;
}

int List::empty() {
	if (head == NULL){
		return 1;
	} else {
		return 0;
	}
}

int List::getCount() {
	return count;
}

/*Node *List::getHead() {
	
}*/

void List::print() {
	if (!empty()) { // follow the links, printing as we go
		//similar to deconstructor logic, but instead of deleting, we print
		Node* currentPtr = this->head;
		while (currentPtr != NULL){
			std::cout << currentPtr->data;
			currentPtr = currentPtr->next;
		}
		std::cout << std::endl;
	} else {
		printf("empty\n");
	}
}
//end of List functions

