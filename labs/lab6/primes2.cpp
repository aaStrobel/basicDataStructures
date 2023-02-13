// Lab 6: Is it prime?
// Programmed by Austin Strobel
// Last written: 10/12/22
// Description: this program prints out prime numbers
#include <cmath>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

bool isPrimeX(int c);
bool isMax(int& num, int& max); 

int main(int argc, char *argv[]) {


	//got some of the following code from Blake's notes
	vector<int> primes;
	vector<int>::iterator it;
	int max = 0, old_max = 0, num; //I added num here

	//when handle cache update
	while (cin >> num){
		max = num; 
		for(int i = old_max+1; i <= max; i++){
			if(isPrimeX(i)){
				primes.push_back(i);
				if (isMax(i, old_max)){
					old_max = i;
				}
			} 
		}
		it = find(primes.begin(), primes.end(), num);
		if (it != primes.end()){
			printf("prime\n");
		} 
		else printf("not prime\n");
		//check bitmap
		// if(primes.at(num)) printf("prime\n"); can use this for part 3
		//if (primes.at(num)) printf("prime\n");
		//else printf("not prime\n");
	}

/*
	int number;
	int max = -1;
	//string isPrimeStr;
	vector<int> myVec;

	while(cin >> number){
		isMax(number, max);
		myVec.push_back(number); 	
		if (isPrimeX(number)){
			cout << "prime" << endl;
		} else {
			cout << "not prime" << endl;		
		}
	}
*/
	return 0;
}

bool isMax(int& num, int& max){
	if (num > max){
		max = num;
		return 1;
	}	
	return 0;
}

bool isPrimeX(int c){
	for (int j = 2; j <= sqrt(c); j++){
		if (c == 1){
			return false;
		}
		if (c % j == 0){
			return false;
		}
	}
	return true;
}

