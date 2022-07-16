/*  Professor Scott, digits.cc
    
    Most complicated program of this supplement to illustrate 
    while loops to find digits in a user-supplied number.  Note 
    that C++ does not have a built-in power function like C, so 
    we compute it as we go.

    1/21/21 */

#include <iostream>
using namespace std;

int main () {

  int number;   // a user-supplied number
  int digit;    // how many digits
  int power;    // a power of 10

  // ask the user for a number, repeat until successful
  do {
  
    cout << "Please enter a number greater than 0: ";
    cin >> number;   // get number from input stream

  } while (number < 0);

  digit = power = 1;    /// initialize our counters

  // number has at least one digit, so we use a do/while here
  // its also perfectly valid to use a while loop here
  do {

    digit++;
    power *= 10;   // NOTE:  no built-in power function in C++, so we 
                   //        compute as we go

  } while (((int) number/power) > 1);  // using (int) typecasts this as an int
  // NOTE:  typecasts are not always needed, but make your code clearer  

  // for each of the digits calculate leftmost digit and remainder
  for (int i = 1; i < digit; i++) {

    power /= 10;
    int leftdig = (int) number / power;   // left digit
    number = number % power;              // remainder (n-1 digits)

    // display left digit, remainder, and current power to the user
    cout << leftdig << "  " << number << "  " << power << endl;
  
  }

}  // end of main
