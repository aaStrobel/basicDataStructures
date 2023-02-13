/*#include <iostream>
class C4Col {
    private:
        int numDiscs;
        int maxDiscs;
        char discs[6];

    public:
        C4Col();
        int isFull(); //determines if column is full (numDiscs == maxDiscs)
        char getDisc(int d); //returns requested element of "discs"
        int getMaxDiscs();
        void addDisc(char c); //adds char to next open slot in "discs"
}*/

/*looked at https://docs.microsoft.com/en-us/cpp/cpp/primary-expressions?view=msvc-170 and https://stackoverflow.com/questions/17259531/c-primary-expressions-is-it-primary-expression-or-not
 * to look up what a "primary expression" is
 *
 *
 *
 *
 */

#include "C4Col.h"
#include <iostream>

using namespace std;

C4Col::C4Col(){

	//default constructor
	numDiscs = 0;
	maxDiscs = 6;

	//displays asterisks for every column
	for (int i = 0; i < maxDiscs; i++){
		discs[i] = '*';	
	}

}

int C4Col::isFull(){

	//is true if a column is full
	if (numDiscs == maxDiscs){
		return 1;
	} else {
		return 0;
	}

}

char C4Col::getDisc(int d){

	//if the input column number is out of this range, then a null character is returned
	if ((d < 0) || (d > 6)){
		return '\0'; //\0 - null character
	}

	return discs[d];
}

int C4Col::getMaxDiscs(){

	return maxDiscs;	

}

void C4Col::addDisc(char c){

	//is a column isn't full, then the disc position in a column is set to the discs array at that position
	if (isFull() == 1){
		cout << "Column is full." << endl;
	} else {
		discs[numDiscs] = c;
		numDiscs++;
	}

}


