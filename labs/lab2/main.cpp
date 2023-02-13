/*Coded by Austin Strobel
 *Last day that additions were made: 9/2/22
 *This program starts with an empty Connect 4 board (initialized with asterisks), and input is read in 
 *through the terminal (ex. printf '0 1 0 1 0 1 0' | ./main to fill in spots and determine a winner
 *
 * */

//spoke with TA Andrew on 9/8/22 
//spoke with TA Blake and TA Andrew on 9/9/22 about getting the X's and O's to display...
//looked at https://docs.microsoft.com/en-us/cpp/cpp/program-termination?view=msvc-170 to find out how to terminate a loop using "exit"
//asked two questions on Piazza about checking for horizontal wins and diagonal wins
//talked with Robert, the TA at Pellissippi, about checking for diagonal wins

#include "C4Board.h"   // class definition for C4Board used below

int main() {
  C4Board c4;   // instantiate an instance of a C4Board object
  c4.play();        // play game!!
}
