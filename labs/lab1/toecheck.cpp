#include <iostream>

using namespace std;

/*Author: Austin Strobel
 * This is an interactive game of tic-tac-toe where a winner, if there is one, is determined
 * Last edited: 8/28/22
 */

//make sure to elaborate on the description

//*Looked at https://www.geeksforgeeks.org/multidimensional-arrays-c-cpp/ 
//*Looked at Blake's slides presentation
//*Looked at https://cplusplus.com/forum/beginner/9126/ for inspiration
//*Got help on the for loop for displaying the board with new user input on Piazza
//*Spoke with GTA Blake via Zoom on 9/2/22 on displaying user input, determining if
//a player has won after each turn, and checking if a cell has already been chosen
//got lots of feedback from instructors and TAs on Piazza

int main(){
	char c;
	int size, index = 0;
	//i and j are used to define "x and y" for positions in the 2d array

	cin >> size;

	char board[size][size];

	//!= with && is the same as == and ||
	while(cin >> c) {
		if ((c != '-') && (c != 'X') && (c != 'O')){
			continue;
		}
		board[index / size][index % size] = c;
		index++;
	}

/*	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}*/
	
	//now we can see who wins the game                                                  

	//do git pull in /home/astrobel/cs202
	int count = 0;
	char c1 = 't';
	
	//diagonal top left to bottom right
	for (int i = 0; i < size; i++){
		if ((c1 == 't') && (board[i][i] != '-')){
			c1 = board[i][i];
		} else if (board[i][i] == c1){
			count++;
		} else {
			break;
		}

		if (count == (size - 1)){
			cout << board[0][0] << " wins" << endl;
			return 1;
		}
	}

	count = 0;
	c1 = 't';

	//diagonal top right to bottom left
	for (int i = 0, j = size - 1; j >= 0; i++, j--){
		if ((c1 == 't') && (board[i][j] != '-')){
			c1 = board[i][j];
		} else if (board[i][j] == c1){
			count++;
		} else {
			break;
		}
		if (count == (size - 1)){
			cout << board[0][size - 1] << " wins" << endl;
		return 1;
		}
	}

	count = 0;
	c1 = 't';

	//horizontal
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if ((c1 == 't') && (board[i][j] != '-')){
				c1 = board[i][j];
			} else if (board[i][j] == c1){
				count++;
			} else {
				break;
			}
			if (count == (size - 1)){
				cout << board[i][j] << " wins" << endl;
				return 1;
			}
		}
		count = 0;
		c1 = 't';
	}

	count = 0;
	c1 = 't';

	//vertical
	for (int j = 0; j < size; j++){
		for (int i = 0; i < size; i++){
			if ((c1 == 't') && (board[i][j] != '-')){
				c1 = board[i][j];
			} else if (board[i][j] == c1){
				count++;
			} else {
				break;
			}
			if (count == (size - 1)){
				cout << board[i][j] << " wins" << endl;
				return 1;
			}
		}
		count = 0;
		c1 = 't';
	}

	cout << "Tie" << endl;

	return 0;
}

