#include <iostream>

using namespace std;

/*Author: Austin Strobel
 * This is an interactive game of tic-tac-toe where a winner, if there is one, is determined
 * Last edited: 8/28/22
 */
//trololololol
//*Looked at https://www.geeksforgeeks.org/multidimensional-arrays-c-cpp/ 
//*Looked at Blake's slides presentation
//*Looked at https://cplusplus.com/forum/beginner/9126/ for inspiration
//*Got help on the for loop for displaying the board with new user input on Piazza
//*Spoke with GTA Blake via Zoom on 9/2/22 on displaying user input, determining if
//a player has won after each turn, and checking if a cell has already been chosen

int main(){
	char player = ' ';
	//player alternates between X and O
	int turn = 0, size, i, j;
	//i and j are used to define "x and y" for positions in the 2d array

	cout << "Grid size: " << endl;

	cin >> size;

	char board[size][size];

	for(i = 0; i < size; i++) {
		for(j = 0; j < size; j++) {
			board[i][j] = '-';
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	while (turn < (size * size)) {
		int r = 0;
		int c = 0;
		int count = 0;
		char c1 = 't';

		if (turn % 2 == 0){
			player = 'X';
		}
		else {
			player = 'O';
		}

		cout << "Row: ";
		cin >> r;
		cout << "Column: ";
		cin >> c;

		if ((r >= size) || (r < 0)){
			return 1;
		} else if ((c >= size) || (c < 0)){
			return 1;
		} 

		if (board[r][c] != '-'){
			cout << "Spot " << board[r][c] << " already chosen." << endl;
			continue;
		}

		board[r][c] = player;

		for(i = 0; i < size; i++) {
			for(j = 0; j < size; j++) {
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
	
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
				cout << player << " wins" << endl;
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
				cout << player << " wins" << endl;
				return 1;
			}
		}

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
			}
			if (count == (size - 1)){
				cout << player << " wins" << endl;
				return 1;
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
			}
			if (count == (size - 1)){
				cout << player << " wins" << endl;
				return 1;
			}
			count = 0;
			c1 = 't';
		}

		//play the game
		turn++;

		if (turn == (size*size)){
			cout << "Tie" << endl;
			return 1;
		}	

	}


	return 0;
}
