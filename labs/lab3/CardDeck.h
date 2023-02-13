#ifndef _CARDDECK_H_
#define _CARDDECK_H_

#include <iostream>

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
		void deal(int *&hand, int handSize); //takes int array (hand) and returns hand + 1 card
};

#endif

