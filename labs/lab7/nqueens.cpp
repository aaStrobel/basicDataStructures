//Lab 7:  N-queens using backtracking 
//Programmed by Austin Strobel
//Last edited: 10/24/22
//This program outputs a "chess board" showing all possible outcomes of the board with no more than one queen in each column, row, and diagonal
//Got some of the code from TAs Andrew and Blake 

#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

void nqueens(int board[], int start, int size);
//take in the board as an array, the starting point (0), and the size (n)
//given that there are no more than one queen in each column, row or diagonal, the board is output 

int main(int argc, char *argv[]) {

	int size = atoi(argv[1]);
	int board[10];

	nqueens(board, 0, size);
//	cout << endl << setprecision(0) << fixed << pow(size, size) << endl;

	return 0;

}

void nqueens(int board[], int start, int size){
	if (size == start){
		for (int i = 0; i < size; i++){
			for (int j = i + 1; j < size; j++){
				if (board[i] == board[j]) return;	
				if(abs(board[i] - board[j]) == abs(i - j)) return;
			}
		}
		for (int i = 0; i < size; i++){
			if (i == size - 1) cout << board[i] << endl;
			//if the last element in a row has been reached, print that out without a comma
			else cout << board[i] << ", ";
			//if the last element in a row hasn't been reached, print that out with a comma
		}
	} else {
		for (int i = 0; i < size; i++){
			board[start] = i;
			nqueens(board, start + 1, size);
		}
	}
}

