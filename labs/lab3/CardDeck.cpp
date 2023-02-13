#include "CardDeck.h"
#include <algorithm>
#include <iostream>

using namespace std;

/* #include <iostream>

   class CardDeck {
   private:
	int *deck;
	int size;
   public:
	CardDeck(int n = 52);
	CardDeck(const CardDeck &obj);
	~CardDeck(); //deconstructor

	const CardDeck &operator=(const CardDeck &obj);

	int getSize(); //returns size of current deck
	void shuffle();
	void display();
	void deal(int *&hand, int size); //takes int array (hand) and returns hand + 1 card
}; 
   */

CardDeck::CardDeck(int n) {
	size = n;
	deck = new int [size];
	for(int i = 0; i < n; i++){
		deck[i] = (i % 10) + 2;
	}
}

CardDeck::CardDeck(const CardDeck &obj){
	deck = obj.deck;
}

CardDeck::~CardDeck(){
	delete [] deck;
}

//copied from Dr. Emrich's "Rule of Three" notes -> from Blake's PowerPoint (a lot of the code here is)
const CardDeck &CardDeck::operator=(const CardDeck &obj) {
	if (&obj != this) { // avoid self-assignment
		if (size != obj.size) {
			delete [] deck; // release space
			size = obj.size; // resize this object
			deck = new int[size]; // create space for array copy
		} // end inner if
		for (int i = 0; i < size; i++){
			deck[i] = obj.deck[i]; // copy array into object
		}
	}
	return (*this); // enables x = y = z, for example
}

int CardDeck::getSize(){
	return (size);
}

void CardDeck::shuffle() {
	random_shuffle(&deck[0], &deck[size]);
}

void CardDeck::display(){
	for (int i = 0; i < size; i++){
		cout << deck[i] << " ";
	}
	cout << endl;
}

//function to get cards from deck and store in player/dealer hand
void CardDeck::deal(int *&hand, int handSize) {
	int *new_hand = new int [handSize + 1];
	for(int i = 0; i < handSize; i++){ //copy hand
		new_hand[i] = hand[i];
	}

	delete[] hand;
	//draw card from deck and add it to new_hand
	new_hand[handSize] = deck[0];
	
	hand = new_hand;
	
	int *new_deck = new int [size - 1];
	size--;
	//size-- actually decreases the size of the deck
	for (int i = 0; i < size; i++){
		new_deck[i] = deck[i + 1];
	}
	delete[] deck;
	//gotta delete it cuz we're changing the size or somethin'

	deck = new_deck;
}


