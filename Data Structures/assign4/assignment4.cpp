/*
Programmer: Harry Chieng
Z-ID: z1811457
Due Date: 02/23/2018

Function: In the implementation of the class, you are going to use stacks s1 and s2 to store and manipulate data. You are suggested to use only s1 to save the element just "pushed" in (i.e. unqueueed), and use s2 to hold older elements. 
*/

#include <iostream>
#include <iomanip>
#include <stack>
#include <cstring>
#include "assignment4.hpp"

using std::stack;
using std::string;
using std::cout;
using std::endl;
using std::cerr;
using std::cin;
using std::setw;

bool Queue::empty() const {	//makes sure that both s1 and s2 are empty
	if(s1.empty() && s2.empty())
		return 1;
	else
		return 0;
}
int Queue::size() const {	//you need to count the number of elements in both s1 and s2
	return s1.size() + s2.size();
}

int Queue::front() {	//the method returns the oldest element. 
	while(!s1.empty()) {	//move elements from s1 to s2
		s2.push(s1.top());
		s1.pop();
	}
	return s2.top();	//return top element in s2
}

int Queue::back() {	//returns the newest element
	while(!s2.empty()) {
		s1.push(s2.top());
		s2.pop();
	}
	return s1.top();	//return the top element in s1
}

void Queue::push(const int& val) {	//add the element to s1
	while(!s2.empty()) {
		s1.push(s2.top());
		s2.pop();
	}
		s1.push(val);
}

void Queue::pop() {	//method remove the oldest element. Can reuse front()
	while(s1.size() != 0) {	//move elements from s1 to s2
		s2.push(s1.top());
		s1.pop();	
	}	
	s2.pop();	//deletes the element	
}

int main() {
	Queue q;
	string op;
	int val = 0;

	cout << "operation -- size front end" << endl;
	cin >> op;
	while ( !cin.eof() ) {
		if ( op == "push" ) {
			cin >> val;
			q.push( val );
			cout << op << " " << val << "    -- ";
		}
		else if ( op == "pop" ) {
			q.pop();
			cout << op << "       -- ";
		}
		else {
			cerr << "Error input: " << op << endl;
			return 1;
		}
		cout << setw(3) << q.size() << setw(5) << q.front() << setw(5) << q.back() << endl;
		cin >> op;
	}

	while ( !q.empty() )
		q.pop();

	return 0;
}
