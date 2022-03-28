#ifndef _STACK_H
#define _STACK_H

#include <iostream>
class Stack{
	private:
		int* sArray;
		size_t sCapacity;
		size_t sSize;


	public:
		Stack();
		~Stack();
		Stack(const Stack& other);
		Stack& operator=(const Stack& other);
		friend std::ostream& operator<<(std::ostream& lhs, const Stack& rhs);

		void clear();
		size_t size()const;
		size_t capacity()const;
		bool empty()const;
		int top ()const;
		void push(int val);
		void pop();
		void reserve(size_t n);
		int operator[](size_t n)const;
		int& operator[](size_t n);
		bool operator==(const Stack& rhs) const;
};
#endif
