#include <iostream>
#include <ctype.h>
#include <cstdio>

using namespace std;

/*Created by Austin Strobel
 * Uses ASCII values of uppercase letters (ignores periods and dashes) to determine the total "amount of gold" these letters "are worth"
 * Last day edited: 8/29/2022
 */

//looked at https://www.includehelp.com/tips/cpp/print-character-through-ascii-value-using-cout.aspx
//looked at https://cplusplus.com/reference/cctype/isalpha/
//looked at https://www.tutorialspoint.com/isalpha-and-isdigit-in-c-cplusplus
//watched Dr. Emrich's Youtube video and visited him in his office on 8/29/22 to get help on the code and Unix commands

int main(){

	char c;
	int val, sum;
	
	sum = 0;

	while (cin >> c) {
		val = c;
		val -= 64;

		if (val >= 1){
			sum += val;
		}

	}
	cout << sum << endl;
}

