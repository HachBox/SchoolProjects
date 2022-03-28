/*
Name: Harry Chieng

Section Number: 002

Purpose: 
To find and print all prime numbers within a range [lower upper] 
using the algorithm known as the Sieve of Eratosthenes.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <set>
#include <string>

using std::setw;
using std::cin;
using std::cout;
using std::set;
using std::endl;
using std::string;

void sieve( set<int>& s, const int lower, const int upper) {
	for(int i = lower; i < upper; ++i)		
		s.insert(i);	//inserts numbers into the set
	s.erase(1);	//deletes 1, because irrelevant
	for(int i = 2; i < sqrt(upper); i++) {
		for(int j = i*i; j <= upper; j+=i) {	//scans set the divisioning in "j+=i" increment j by i values
			s.erase(j);	//erases numbers that aren't prime
		}
	}	
}

void print_primes( const set<int>& s, const int lower, const int upper) {
	cout << "There are " << s.size() << " prime numbers between " << lower << " to " << upper << ":" << endl;
	int i = 0;
	for(auto&prime:s) {
		cout << setw(6) << prime << " ";	//prints out the prime numbers
		if(++i%6 == 0)
			cout << endl;	//prints out the numbers in columns of 6
	}
	cout << endl;
}

void run_game(set<int>& s) {
	int lower;
	int upper;
	cout << "Please input lower bound and upper bound and hit enter (e.g. 10 100): ";
	cin >> lower >> upper;
	sieve(s,lower,upper);	//calls sieve function
	print_primes(s,lower,upper);	//prints prime numbers
}

int main() {
	set<int> s;
	string i;
	do {
		run_game(s);	//return to do this function again
		cout << "Do you want to continue or not? Please answer yes or no and hit enter: ";
		cin >> i;
	}
	while(i == "yes");
	return 0;
}
