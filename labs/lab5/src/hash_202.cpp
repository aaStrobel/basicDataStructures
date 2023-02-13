/*Authored by Austin Strobel
 *Last edited: 09/28/22
 *Description: We will be using hash functions (either Last7 or XOR) to calculate an index to place a key-value pair in. If a collission occurs, one of two resolution strategies (Linear or Double Hashing) has to be used.
 *
 *
 */
//THIS IS THE ONLY FILE I WILL SUBMIT
//Got help at office hours 10/3/22, and spoke with Robert from PSTCC
//Looked at https://stackoverflow.com/questions/8899069/how-to-find-if-a-given-string-conforms-to-hex-notation-eg-0x34ff-without-regex
//Looked at https://www.digitalocean.com/community/tutorials/hash-table-in-c-plus-plus

#include "hash_202.hpp"
#include <cctype>
#include <string>//prob don't need this anymore
#include <algorithm> //used for all_of in hex for loop. might not need this boi anymore
#include <cstdio> // printf
#include <iostream> // >>
#include <sstream> // istringstream

using namespace std;


const int XOR_FXN = 1;
const int LAST7_FXN = 0;
const int LINEAR_COLLRES = 69;
const int DOUBLE_COLLRES = 70;

//this was &key (and for XOR)
int Last7(const string &key){ //this has to be const bcuz of parallelism...what a joy
	//got some of this code from the lab write-up
	string temp;
	istringstream ss;
	int i;

	if (key.length() <= 7){
		temp = key;
	} else {
		temp = key.substr((int)key.length() - 7, 7);
	}

	ss.clear();
	ss.str(temp);
	(ss >> hex >> i);
	return i;
}

int XOR(const string &key){
	//fix this bad boi
	int start = 0;
	istringstream ss;
	int i;
	string temp;
	int hash = 0;
	int numChars = 7;
	while (start < (int)key.length()){
		if (numChars >= (int)key.length() - start) numChars = key.length() - start;
		temp = key.substr(start, numChars);

		//cout different parts

		//hash ^= stoi(temp, NULL, 16);
		ss.clear();
		ss.str(temp);
		(ss >> hex >> i);
		hash ^= i;
		start += numChars;
	}
	return hash;
}

//Stuff from his video: stringstreams to convert to hex...
//size_t is unsigned long
//for double hashing, you call the other function that you didn't use

//DATA MEMBERS
/* Obviously, you can use these however you want, but here is how I used them.  You may
   not modify or add to this header file, so you need to be able to implement the lab with
   just these member variables. */

//vector <string> Keys;   // The hash table of keys.
//vector <string> Vals;   // The Vals[i] is the val associated with Keys[i]
//size_t Nkeys;                     // This is the number of keys that have been inserted.
//int Fxn;                          // The hash function.  I have 0 = "Xor" and 1 = "Last7".
//int Coll;                         // The collision resolution strategy.  0 = Linear. 1 = Double
//size_t Nprobes;                   // When I call Find(), I set this value to the number of probes.
//END DATA MEMBERS

/* You must call Set_Up() to set up the table before using it.  This method 
   takes the hash table size, a name of a hash function (either "Last7" or "XOR"), and
   the name of a collision resolution strategy (either "Linear" or "Double").  

   You should error check your input, and look for the following errors, in the following
   order.  If you see one of these errors, return the string specified:

   - Table already set up:                "Hash table already set up"
   - Bad table size:                      "Bad table size"
   - Bad hash function:                   "Bad hash function"
   - Bad collision resolution strategy:   "Bad collision resolution strategy" */
string Hash_202::Set_Up(size_t table_size, const string &fxn, const string &collision)
{
	if (Keys.size() > 0){
		return "Hash table already set up.";
	}
	//make global bool, make those two fxn's equal to 0 or 1 - initialixe each to -1
	//check for bad table size
	if (table_size == 0){
		return "Bad table size";
	}
	//check for bad hash function
	if (fxn == "XOR"){
		Fxn = XOR_FXN;
	} else if (fxn == "Last7"){
		Fxn = LAST7_FXN;
	} else {
		return "Bad hash function";
	}
	//check for bad collision resolution strategy
	if (collision == "Linear"){
		Coll = LINEAR_COLLRES;
	} else if (collision == "Double"){
		Coll = DOUBLE_COLLRES;
	} else {
		return "Bad collision resolution strategy";
	}
	//resize table (Keys & Vals vector) + initialize Nkeys to 0
	Keys.resize(table_size, "");
	Vals.resize(table_size, "");

	Nprobes = 0;
	Nkeys = 0;

	return "";
}

/* Add() adds the given key/val pair to the hash table.  If successful, it should return
   an empty string.  Add should test for the following errors, in this order,
   and return the given strings:

   - Table not set up:                "Hash table not set up"
   - Empty string for the key:        "Empty key"
   - Key not composed of hex digits:  "Bad key (not all hex digits)"
   - Empty string for the val:        "Empty val"
   - The hash table is full:          "Hash table full"
   - Cannot insert key:               "Cannot insert key"
   - The key is already in the table  "Key already in the table"
   */ 
string Hash_202::Add(const string &key, const string &val)
{
	//deal with collisions - add key-val pair to their vectors
	//check for empty slots 
	int count = 0, index = 0, hash, index2;
	vector<bool> v;
	v.resize(Keys.size(), false);
	//hash function is to calculate what index we should start at
	//should start with last7 and linear hashing
	//check if table not set up
	if (Keys.size() == 0){
		return "Hash table not set up";
	}
	//check if empty string for key
	if (key == ""){
		return "Empty key";
	}
	//check if key not composed of hex digits
	//got this function from Stack Overflow
	for (int i = 0; i < (int)key.length(); i++){
		if (!isxdigit(key[i])) return "Bad key (not all hex digits)";
	}
	//check if empty string for val
	if (val == ""){
		return "Empty val";
	}
	//check if hash table is full
	if (Nkeys >= Keys.size()){
		return "Hash table full";
	}

	if (Fxn == XOR_FXN){
		index = XOR(key) % Keys.size();
	} else {
		index = Last7(key) % Keys.size();
	}
	//check if key is already in table
	if (Keys[index] != ""){
		if (Coll == LINEAR_COLLRES){
			if (Keys[index] == key){
				return "Key already in the table";
			} 
			else {
				count = 0;
				while (count < (int)Keys.size()){	
					index++;
					index %= Keys.size();
					if (Keys[index] != ""){
						if (Keys[index] == key){
							return "Key already in the table";
						}
					}
					else {
						Keys[index] = key;
						Vals[index] = val;
						Nkeys++;
						return "";
					}
					count++;
				}
				return "Cannot insert key";
			}	
		}
		else {
			//Coll = DOUBLE_COLLRES
			if (Keys[index] == key){
				return "Key already in the table";
			}
			else {
				v[index] = true;
				while (1){

					if (Fxn == XOR_FXN){
						hash = Last7(key);
					} else {
						hash = XOR(key);
					}

					index2 = hash % Keys.size();


					if (index2 == 0){
						index2 = 1;
					}

					index += index2;
					index %= Keys.size();

					if (v[index]){
						break;
					}

					if (Keys[index] != ""){
						if (Keys[index] == key){
							return "Key already in the table";
						}
						else {
							v[index] = true;
						}
					}
					else {
						Keys[index] = key;
						Vals[index] = val;
						Nkeys++;
						return "";
					}
				}
			}
			return "Cannot insert key";
		}
		//rehash once
		//try twice
		//try again to insert at new index
		//if last7 is declared, XOR is used
	}

	//get index

	//get probe increment
	//Nprobes++;

	//insert into table
	Keys[index] = key;
	Vals[index] = val;
	//handle collisions

	//increment Nkeys
	Nkeys++;

	return "";
}

/* Find() returns the val associated with the given key.  If the hash table has not been 
   set up yet, or if the key is not in the hash table, or if the key is not composed of
   all hex digits, it should return an empty string. 

   Find() is not const, because it sets the variable Nprobes to equal the number of
   probes that it took  to find the answer. */

//looking for key instead of empty space 
//hash key, check index, if key matches, return index to val
//if empty, the key aint in there
// if the index isn't the key, then there's a collission - > collission strats
string Hash_202::Find(const string &key)
{
	string val;
	//deal with collisions - add key-val pair to their vectors
	//check for empty slots 
	int count = 0, index = 0, hash, index2;
	vector<bool> v;
	v.resize(Keys.size(), false);
	//hash function is to calculate what index we should start at
	//should start with last7 and linear hashing
	//check if table not set up
	if (Keys.size() == 0){
		return "";
	}
	//check if empty string for key
	if (key == ""){
		return "";
	}
	//check if key not composed of hex digits
	//got this function from Stack Overflow
	for (int i = 0; i < (int)key.length(); i++){
		if (!isxdigit(key[i])) return "";
	}

	if (Fxn == XOR_FXN){
		index = XOR(key) % Keys.size();
	} else {
		index = Last7(key) % Keys.size();
	}

	if (Keys[index] == ""){
		return "";
	}

	Nprobes = 0;
	if (Keys[index] != key){
		if (Coll == LINEAR_COLLRES){
			count = 0;
			while (count < (int)Keys.size()){	
				Nprobes++;
				index++;
				index %= Keys.size();
				if (Keys[index] == key){
					return Vals[index];
				} else if (Keys[index] == ""){
					return "";
				}
				count++;
			}
			return "";
		}
		else {
			v[index] = true;
			while (1){
				Nprobes++;
				if (Fxn == XOR_FXN){
					hash = Last7(key);
				} else {
					hash = XOR(key);
				}

				index2= hash % Keys.size();

				if (index2 == 0){
					index2 = 1;
				}

				index += index2;
				index %= Keys.size();

				if (v[index]){//if v[index] remains true
					break;
				}

				if (Keys[index] == key){
					return Vals[index];
				} else if (Keys[index] == ""){
					return "";
				} else {
					v[index] = true;
				}
			}
			//}
			return "";
			//}
			//rehash once
			//try twice
			//try again to insert at new index
			//if last7 is declared, XOR is used
		}

	}

	return Vals[index]; // "" if key not in hash table

}

/* Print() prints all non-empty slots in the hash table, one per line. 
   The index should be printed first, right justified and padded to five characters. 
   Then a space, the key, a space, and the val. This should do nothing if the hash
   table has not been set up yet. */
void Hash_202::Print() const
{
	//if table has been set up
	if(Keys.size() != 0) {
		for(unsigned long int i = 0; i < Keys.size(); i++) {
			//print if not empty
			if(Keys.at(i) != "") 
				printf("%5lu %s %s\n", i, Keys.at(i).c_str(), Vals.at(i).c_str());
		}
	}
}

/* 
   Total_Probes() should traverse the hash table, and for every key, caculcate how many probes
   it takes find that key.  It should return the total number of probes.  It should
   return 0 if the hash table has not been set up yet.  It is not const, because it 
   uses Find() to find the number of probes for each key. 
   */
size_t Hash_202::Total_Probes()
{
	size_t sum = 0;

	if(Keys.size() != 0) {
		for(unsigned long int i = 0; i < Keys.size(); i++) {
			if(Keys.at(i) != "") { //don't include empty strings
				Find(Keys.at(i));
				sum += Nprobes;
			}
		}
	}

	return sum; //error: sum = 0 if table not setup
}

