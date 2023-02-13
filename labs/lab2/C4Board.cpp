/*#include <iostream>
#include "C4Col.h"

class C4Board {

    private:
        int numCol;
        C4Col Board[100];

    public:
        C4Board();
        void display(); //displays current board
        void play(); //allows two players to play
        int win(); //check for winner

};*/

#include "C4Board.h"
#include <iostream>

using namespace std;

C4Board::C4Board(){

	numCol = 7;

}

void C4Board::display(){

	cout << endl;
	cout << "  0   1   2   3   4   5   6  " << endl;  
	for (int i = Board[0].getMaxDiscs() - 1; i >= 0; i--) { 
		//number of rows
		for (int j = 0; j < numCol; j++){ 
			//number of columns
			cout << "| " << Board[j].getDisc(i) << " ";
		}
		cout << "|"  << endl;
	}
}

void C4Board::play() {
	
	int turn = 0, c;
	char player;

	display();	
	
	while (true){
		//alternating between X and O
		if (((turn % 2) + 1) == 1){
			player = 'X';
		} else {
			player = 'O';
		}

		//asking the user for a column
		cout << "Column: ";
		cin >> c;
		while ((c < 0) || (c > 6) || Board[c].isFull()){
			if (c == -1){
				exit(3);
			} else if ((c < 0) || (c > 6)){
				cout << "Try again. Column: ";
				cin >> c;
			} else if (Board[c].isFull()){
				cout << "Column full. Try again: ";
				cin >> c;
			}
		}

		//adding that input disc to the board
		Board[c].addDisc(player);
		display();
		//displaying the board the checking for a win
		win();
		turn++;

	}

}

int C4Board::win(){

	int count;

	//horizontal
	for (int i = 0; i < Board[0].getMaxDiscs() - 1; i++){
		//rows
		for (int j = 0; j < numCol; j++){
			//columns
			if (Board[i].getDisc(j) != '*'){
				count = 0;
				if (Board[i+1].getDisc(j) == Board[i].getDisc(j)){
					count++;
				}
				if (Board[i+2].getDisc(j) == Board[i].getDisc(j)){
					count++;
				}
				if (Board[i+3].getDisc(j) == Board[i].getDisc(j)){
					count++;
				}
			}			
			else {
				break;
			}
			if (count == 3){
				cout << Board[i].getDisc(j) << " wins!" << endl;
				exit(3);
			}
		}
	}

	//vertical
	for (int i = 0; i < numCol; i++){
		//columns
		for (int j = 0; j < Board[i].getMaxDiscs(); j++){
			//rows
			if (Board[i].getDisc(j) != '*'){
				count = 0;
				if (Board[i].getDisc(j+1) == Board[i].getDisc(j)){
					count++;
				}
				if (Board[i].getDisc(j+2) == Board[i].getDisc(j)){
					count++;
				}
				if (Board[i].getDisc(j+3) == Board[i].getDisc(j)){
					count++;
				}
			}			
			else {
				break;
			}
			if (count == 3){
				cout << Board[i].getDisc(j) << " wins!" << endl;
				exit(3);
			}
		}
	}

	//diagonal top left to bottom right
	for (int i = 3; i < 6; i++){
		//columns
		for (int j = 0; j < 4; j++){
			//rows
			//for the if statement, if 4 in a row are the same character (X or O), then that character wins
			if ((Board[j].getDisc(i) == Board[j+1].getDisc(i-1)) &&
				(Board[j].getDisc(i) == Board[j+2].getDisc(i-2)) && 
				(Board[j].getDisc(i) == Board[j+3].getDisc(i-3)) &&
				(Board[j].getDisc(i) != '*')){
				cout << Board[j].getDisc(i) << " wins!" << endl;
				exit(3);
			}
		}
	}

	//diagonal top right to bottom left
	for (int i = 3; i < 6; i++){
		//columns
		for (int j = 6; j > 2; j--){
			//rows
			//for the if statement, if 4 in a row are the same character (X or O), then that character wins
			if ((Board[j].getDisc(i) == Board[j-1].getDisc(i-1)) &&
				(Board[j].getDisc(i) == Board[j-2].getDisc(i-2)) && 
				(Board[j].getDisc(i) == Board[j-3].getDisc(i-3)) &&
				(Board[j].getDisc(i) != '*')){
				cout << Board[j].getDisc(i) << " wins!" << endl;
				exit(3);
			}
		}
	}

	return 0;
}

