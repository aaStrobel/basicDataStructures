// Lab 7:  N-queens using backtracking 
//Programmed by Austin Strobel
//Last edited: 10/19/22
//This program outputs a "chess board" with n queens, limiting the search space

#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int nqueens(int board[], int start, int size);
//just like nqueens in nqueens.cpp but with a limited search space
bool isValid(int board[], int start);
//separate function for determining if a board is valid (maximum of one queen in each column, row, and diagonal 

int main(int argc, char *argv[]) {

	int size = atoi(argv[1]);
	int board[10];

	cerr << nqueens(board, 0, size) << endl;
//	cout << endl << setprecision(0) << fixed << pow(size, size) << endl;

	return 0;

}

int nqueens(int board[], int start, int size){
	int number = 0;
	//"number" totals the number of boards considered with the limited, but still valid, search space
	if (size == start){
		number = 1;
		if (isValid(board, start)){
			for (int i = 0; i < size; i++){
				if (i == size - 1) cout << board[i] << endl;
				else cout << board[i] << ", ";
			}
		}
	} else {
		for (int i = 0; i < size; i++){
			board[start] = i;
			if (isValid(board, start)){
				number += nqueens(board, start + 1, size);
				//number is totaled, and recursion is used to call the function once again
			}
		}
	}
	return number;
}

bool isValid(int board[], int size){
	for (int i = 0; i < size; i++){
		for (int j = i + 1; j < size; j++){
			if (board[i] == board[j]) return 0;	
			if(abs(board[i] - board[j]) == abs(i - j)) return 0;
		}
	}
	return 1;
}
