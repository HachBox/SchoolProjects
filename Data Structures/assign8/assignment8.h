#ifndef ASSIGNMENT8_H
#define ASSIGNMENT8_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Entry { 
    std::string key;
    std::string description; 
    Entry() { key = "---"; }
};

// This method takes a line of input and parses it to return the item-key.
string get_key (const string& line) {
	return line.substr(2, 3);
//The line is in format of X:item-key, i.e. two strings separated by ‘:’, where the first string is just a single character. 
}

//This method takes a line of input and parses it to create a new Entry
Entry* get_entry (const string& line) {
	Entry *e = new Entry();
	e -> key = get_key(line);
	e -> description = line.substr(6);
	return e;
// The line is in format of A:item-key:itemdescription, 
// i.e., three strings separated by ‘:’, where the first string is just a single character ‘A’.
}

class HT {
    private:
        std::vector<Entry>* hTable;
        int table_size;
        int item_count;
        int hashing(const std::string&);
    public:
	HT(int size = 11);
        ~HT();
	//This public member function inserts item e in the hash table
        bool insert(const Entry&);
	//This public member function searches the hash table for a record with a given key.
        int search(const std::string&);
	// This public member function removes an item with given key s.
        bool remove(const std::string&);
	//This public member function prints the existing entries in the hash table
        void print();
};

#endif
