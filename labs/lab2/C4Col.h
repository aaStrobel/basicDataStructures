#include <iostream>

class C4Col {
	private:
		int numDiscs;
		int maxDiscs;
		char discs[6]; 
	
	public:
		C4Col();
		int isFull(); //determines if column is full (numDiscs == maxDiscs)
		char getDisc(int); //returns requested element of "discs"
		int getMaxDiscs(); //returns the maximum number of discs (number of rows)
		void addDisc(char); //adds char to next open slot in "discs"
};
