/*
Programmer: Harry Chieng
Section: 340 - 002 
Date: 04/09/18
Function:  a C++ program to create, search, print, and manage an item inventory
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include "assignment8.h"

#define HashTable (*hTable)

using namespace std;

// key is in form of letter-letter-digit
// compute sum <-- ascii(pos1)+ascii(pos2)+ascii(pos3)
// compute sum%htable_size

HT::HT(int s) { //This is the constructor. 
	table_size = s;
	item_count = 0;
	hTable = new vector<Entry>(s);
	//The hash table hTable, which is a vector of Entry, is created dynamically (with new operator) for a given size s (with default value 11) here. 
	//Other data members are also properly initialized here.
}

HT::~HT() { //This is the destructor. 
	delete hTable;
	//Since the hash table hTable is implemented as a dynamically created vector, 
	//its memory is released here by delete operator. 
}

//This public member function searches the hash table for a record with a given key.
int HT::search(const std::string& key) {
	int hkey = hashing(key);
	for(int x = 0; x < table_size ; x++) {
		if(HashTable[(x +hkey)%table_size].key == key)
			return hkey; // returns the position of the found item
		else if(HashTable[(x +hkey)%table_size].key == "---")
			return -1;
	}
	return -1;
}

//This public member function inserts item e in the hash table.
bool HT::insert(const Entry& e) {
	if(search(e.key) != -1)	//if the item’s key already exists in the table
		return false;
	if(table_size == item_count) { //If the hash table is already full
		cout << "418 2Hash4U";
		return false;	//prints an error message and returns false 
	}
	//It then needs to compute the hash value of item e’s key. 
	int valueOfLocation = hashing(e.key);
	for(int x = 0; x < table_size; x++) 
		if(HashTable[(x + valueOfLocation)%table_size].key == "---" || HashTable[(x + valueOfLocation)%table_size].key == "+++") {
			HashTable[(x + valueOfLocation)%table_size] = e;
			//If the hash table position of the hash value is empty,
			//the item is placed on that positon 
			//otherwise, an appropriate position is determined by linear probing.
			//After the item is inserted
			item_count++;
			return true;
		}
	return false;
}

//This public member function removes an item with given key s.
bool HT::remove(const std::string& s) {
	int location = search(s);
	if(location != -1) {
		HashTable[location].key = "+++";
		return true;
	}
	else 
		return false;
	//otherwise it removes the entry of the given key by setting its key as “+++”, decreases item_count, and returns true at the end.
}

void HT::print() {

	cout << "----Hash Table-----" << endl;

	for(int x = 0; x != table_size; x++) {
		Entry e = HashTable[x];

		if(e.key != "---" && e.key != "+++") 
		cout << setw(2) << x << setw(2) << ":" << e.key << " " << e.description << endl;
	}

	cout << "-------------------" << endl;
	/*
	   This public member function prints the existing entries in the hash table: 
	   the index value of the position, the key, and the description.
	   */
}

//linear probing search
int HT::hashing(const string& key) {
	return ((int)key[0] + (int)key[1] + (int)key[2])%table_size;
}

int main(int argc, char** argv ) {
	if ( argc < 2 ) {
		cerr << "argument: file-name\n";
		return 1;
	}

	HT ht;
	ifstream infile(argv[1], ios::in);
	string line;
	infile >> line;    
	while ( !infile.eof() ) {
		if ( line[0] == 'A' ) { 
			Entry* e = get_entry( line );
			ht.insert( *e );
			delete e;
		}
		else {
			string key = get_key(line);
			if ( line[0] == 'D' ) {
				cout << "Removing " << key << "...\n";
				bool removed = ht.remove( key );
				if ( removed )
					cout << key << " is removed successfully...\n\n";
				else
					cout << key << " does not exist, no key is removed...\n\n";
			}
			else if ( line[0] == 'S' ) {
				int found = ht.search( key );
				if ( found < 0 ) 
					cout << key << " does not exit in the hash table ..." << endl << endl;
				else
					cout << key << " is found at table position " << found << endl << endl;
			}
			else if ( line[0] == 'P' ) {
				cout << "\nDisplaying the table: " << endl;
				ht.print();
			}
			else
				cerr << "wrong input: " << line << endl;
		}
		infile >> line;

	}

	infile.close();
	return 0;
}
