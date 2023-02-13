//Lab 04: Adding List-Based Integers
//Written by Austin Strobel 
//09/25/2022
//The purpose of this lab is to take in two integers, add them together, and print the output using custom linked lists

//Looked at https://www.programiz.com/cpp-programming/library-function/cstring/strlen 
//Looked at https://en.cppreference.com/w/cpp/string/basic_string
//referenced Problem Solving with C++ by Walter Savitch
//attended office hours on 9/26/22

#include "list.h"
#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <sstream>

using namespace std;

int main(){
	char input[100];
	char* input1, *input2;

//string streams could also work for all this

//	cin.getline(input, 100);
//	stringstream ss(input);

//	ss >> input1 >> input2;

	while(cin.getline(input, 100)){
		List* outputList = new List();
		List* list1 =      new List();
		List* list2 =      new List();
		//strtok (string token) is like substr
		input1 = strtok(input, " ");
		input2 = strtok(NULL, " ");
		//separate lines into individual numbers...
		for (int i = 0; i < strlen(input1); i++){
			list1->addNode(input1[i]);		
		}

		for (int i = 0; i < strlen(input2); i++){
			list2->addNode(input2[i]);
		}
		
		//strcmp(input1, input2);
		outputList->sumLists(list1, list2);	
		outputList->print();
		delete outputList;
		delete list1;
		delete list2;
	}


	//separate numbers in line
	//	-convert to list
	//	-get sum of numbers
	//	-don't forget to free memory!

	return 0;
}
