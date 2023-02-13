/*  Written by Austin Strobel
 *  Last date edited: 09/19/2022
 *	This programs runs Blackjack, and the player can choose to play just one time or multiple times. The standard rules of the casino game apply
 * */

/*Got a lot of this code from GTA Blake's slides and Dr. Emrich's CS202 website
 *Looked at https://www.geeksforgeeks.org/constructors-c/https://www.geeksforgeeks.org/constructors-c/ to review syntax for copy constructors
 *Looked at https://www.geeksforgeeks.org/destructors-c/ to review syntax for destructors
 *Looked at https://www.geeksforgeeks.org/shuffle-vs-random_shuffle-c/
 *Looked at https://www.programiz.com/cpp-programming/library-function/cstdlib/srand
 *Looked at https://cplusplus.com/reference/algorithm/random_shuffle/
 *Posted a question on Piazza about "undefined reference to" error
 *Went to office hours on 9/16/22 to work on the lab and ask GTAs Blake and Andrew a few questions
 *Looked at codescracker to see how to delete an element of an array
 *Went to the programming clinic on 9/19/22 to work on the lab and ask a question or two
 */

//Comment for myself: for compiling, make sure to do "make clean" and then g++ -o main CardDeck.cpp main.cpp...or just "make"

#include "CardDeck.h"   // class definition for CardDeck used below
#include <iostream>

using namespace std;

int main() {
	int player_win = 0, dealer_win = 0, tie = 0, hHandSize = 2, pHandSize = 2, pSum = 0, hSum = 0;
	//hHandSum is the summation of the card values that the house has (to determine if the house should hit or stand)
	//pSum is the sum of the player's cards, while hSum is the house's sum
	//player_win, dealer_win, and tie are used to count how many times each has occurred
	//hHandSize and pHandSize are the hand sizes for the house and the player
	//initSize is the initial size of a hand (2 cards)
	bool player_stand = false, house_stand = false;
	char pMove = 't', choice;
	//pMove is the player's choice of hitting or standing, h is the house's version of those two options
	int* playerHand = new int [5];
	int* houseHand = new int [5];
	CardDeck * deck; // pointer to a single CardDeck object
	deck = new CardDeck(10);

	deck->display();
	deck->shuffle();
	deck->display();
	delete deck;
	printf("\n");
	deck = new CardDeck(); 
	deck->shuffle();

	//play the game

	do {

		//check for fewer than 15 cards
		if(deck->getSize() < 15) {
			delete deck;
			deck = new CardDeck(10);

			//I commented out the given for loop since, according to Dr. Emrich, the deck should not be shuffled 10 times

			cout << "Opening new deck..." << endl;
			deck->shuffle(); 
			deck->display();
		}

		printf("------------------------------------\n");
		printf("player [%d] | dealer [%d] | tie [%d]\n", player_win, dealer_win, tie);
		printf("------------------------------------\n");

		if (hHandSize == 2){
			//draw for house
			cout << "The house's cards: ";
			for (int i = 0; i < hHandSize; i++){
				deck->deal(houseHand, i);
				hSum += houseHand[i];
				cout << houseHand[i] << " ";
			}
			cout << "(" << hSum << ")" << endl;
			//hHandSize++;
		}

		if (pHandSize == 2){
			//draw for player
			cout << "The player's cards: ";
			for (int i = 0; i < pHandSize; i++){
				deck->deal(playerHand, i);
				pSum += playerHand[i];
				cout << playerHand[i] << " ";
			}
			cout << "(" << pSum << ")" << endl;
			//pHandSize++;
		}

		//player's turn
		while ((!player_stand) && (pSum < 21)) {
			cout << "(h)it/(s)tand: ";	
			cin >> pMove;
			if ((pMove == 'h') || (pMove == 'H')){
				deck->deal(playerHand, pHandSize);
				pHandSize++;
				pSum = 0;
				cout << "The player's cards: ";
				for (int i = 0; i < pHandSize; i++){
					pSum += playerHand[i];
					cout << playerHand[i] << " ";
				}	
				cout << "(" << pSum << ")" << endl;
				
				if (pSum > 21){
					pSum = 0;
					break;
				}

				player_stand = false;

			} else {
				player_stand = true;
			}
		}

		//house's turn
		if(player_stand){
			hSum = 0;
			cout << "The house's cards: ";
			for (int i = 0; i < hHandSize; i++){
				hSum += houseHand[i];
				cout << houseHand[i] << " ";
			}
			cout << "(" << hSum << ")" << endl;

			if (hSum >= 17){
				house_stand = true;
			} else if (hSum > pSum){
				house_stand = true;	
			} else {
				house_stand = false;
			}

			while ((!house_stand) && (hSum < 21)){
				if (!house_stand){
					deck->deal(houseHand, hHandSize);
					hHandSize++;
					hSum = 0;
					cout << "The house's cards: ";
					for (int i = 0; i < hHandSize; i++){
						hSum += houseHand[i];
						cout << houseHand[i] << " ";
					}
					cout << "(" << hSum << ")" << endl;
					if (hSum >= 17){
						house_stand = true;
					} else {
						house_stand = false;
					}
				}
			}
		}
		//both players standing
		//…check who won…

		if ((pSum > hSum) && (pSum <= 21)){
			cout << "You win!" << endl;	
			player_win++;
		} else if ((hSum > pSum) && (hSum <= 21)){
			cout << "The house wins" << endl;
			dealer_win++;
		} else if ((pSum > 21) && (hSum <= 21)){
			cout << "You lose." << endl;
			dealer_win++;
		} else if ((hSum > 21) && (pSum <= 21)){
			cout << "The house loses. You win!" << endl;
			player_win++;
		} else if (hSum == pSum){
			cout << "Tie" << endl;
			tie++;
		}

		delete playerHand;
		delete houseHand;
		
		playerHand = new int [5];
		houseHand = new int [5];

		pHandSize = 2;
		hHandSize = 2;

		player_stand = false;
		
		pSum = 0, hSum = 0;
	
		//delete array (delete keyword) -- delete two arrays, create new ones when start loop over

		printf("Do you wish to continue? (y/n)\nChoice: ");
		scanf(" %c", &choice);
		if(choice == 'y') {
			continue;
		} else break;
		
	} while (true);
	
	return 0;
}

