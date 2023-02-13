#include <iostream>
#include "C4Col.h"

class C4Board {

	private:
		int numCol;
		C4Col Board[7];

	public:
		C4Board();
		void display(); //displays current board
		void play(); //allows two players to play
		int win(); //check for winner

};
