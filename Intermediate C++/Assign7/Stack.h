#ifndef _STACK_H
#define _STACK_H

#include <iostream>
#include <stdexcept>

using std::underflow_error;

template <typename T>
class Stack;

template <typename T>
std::ostream& operator<<(std::ostream&, const Stack<T>&);

template <typename T>
struct Node{
	T value; 
	Node<T>* next;
	Node(T v,Node<T>* n){
		value = v;
		next = n;
	}	//parameters must have a different name
};

template<typename T>
class Stack{

	private:	//data memebers for school thangs
		Node<T>* stkTop;	//a node specialized to T
		size_t sSize;

	public:		//methods and associated functions
		Stack(){	//Constructor
			stkTop=nullptr;
			sSize=0;	
		}

		~Stack(){	//Destructor
			clear();	
		}

		Stack<T>(const Stack<T>& other){ //copy constructor	
			stkTop = other.stkTop;
			sSize = other.sSize; 
			auto nextPointerReference = &stkTop; 	//reference to whatever type stkTop was

			while(*nextPointerReference != nullptr){
				*nextPointerReference=new Node<T> ((*nextPointerReference)->value, (*nextPointerReference)->next);	//new returns a pointer, so don't worry, reference af
				nextPointerReference=&(*nextPointerReference)->next;	//&nextPointerReference is fluid

			}
		}

		Stack<T>& operator=(const Stack<T>& other){	//assignment operator
			if(this == &other)
				return *this;
			clear();
			stkTop = other.stkTop;
			sSize = other.sSize; 
			auto nextPointerReference = &stkTop; 	//reference to whatever type stkTop was

			while(*nextPointerReference != nullptr){
				*nextPointerReference=new Node<T> ((*nextPointerReference)->value, (*nextPointerReference)->next);	//new returns a pointer, so don't worry
				nextPointerReference=&(*nextPointerReference)->next;	//&nextPointerReference is fluid
			}
			return *this;
		}

		void clear(){
			sSize = 0;
			Node<T>* tempNext;	//constructs tempNext
			while(stkTop != nullptr){
				tempNext = stkTop->next;
				delete stkTop;
				stkTop = tempNext;
			}
		}

		size_t size()const{
			return sSize;
		}

		bool empty()const{
			if(sSize == 0)
				return true;
			else
				return false;
		}

		const T& top()const{	//returns a reference to a constant item(T)
			return stkTop->value;	//dereferences stkTop, and gets THAT node's value.
		}

		void push(const T val){
			stkTop = new Node<T> (val, stkTop);	//new node the boring way
			sSize++;
		}

		void pop(){	//void returns nothing
			Node<T>* tempNext;
			tempNext = stkTop->next;
			delete stkTop;
			stkTop = tempNext;
			--sSize;
		}

		friend std::ostream& operator<< <>(std::ostream&, const Stack<T>&);

};

template<typename T>
std::ostream& operator<<(std::ostream& lhs, const Stack<T>& rhs){
	Node<T>* tempPointer;
	tempPointer = rhs.stkTop;
	while (tempPointer != nullptr){
	lhs << " " << tempPointer->value;
	tempPointer = tempPointer->next;
	}
	/*for(int i = 0; i < rhs.sSize; i++)
		lhs<<" "<<rhs.qArray[(rhs.qFront+i)%rhs.qCapacity];*/
	return lhs;
}

#endif
