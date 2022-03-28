#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
#include <stdexcept>

using std::underflow_error;

template<typename T>
class Queue{
	private:	//data memebers for school thangs
		T* qArray;
		size_t qCapacity;
		size_t qSize;
		int qFront;
		int qBack;

	public:		//methods and associated functions
		Queue(){	//Constructor
			qArray=nullptr;
			qSize=0;
			qCapacity=0;
			qFront=0;
			qBack=-1;
		}

		~Queue(){	//Destructor
			delete[] qArray;
		}

		Queue<T>(const Queue<T>& other){
			qArray=nullptr;
			qFront=other.qFront;
			qBack=other.qBack;
			qSize=0;
			reserve(other.qCapacity);
			qSize=other.qSize;
			for(int i = 0; i < qCapacity; i++)
			{
				qArray[i] = other.qArray[i];
			}
		}
		
		Queue<T>& operator=(const Queue<T>& other){	//assignment operator
			if(this == &other)
				return *this;
			qSize = 0;
			reserve(other.qCapacity);	//because function
			qFront = other.qFront;
			qBack = other.qBack;
			qSize = other.qSize;
			for(int i = 0; i < qCapacity; i++)
				qArray[i] = other.qArray[i];
			return *this;
		}
		friend std::ostream& operator<<(std::ostream& lhs, const Queue<T>& rhs){
			for(int i = 0; i < rhs.qSize; i++)
				lhs<<" "<<rhs.qArray[(rhs.qFront+i)%rhs.qCapacity];
			return lhs;
		}


		void clear(){
			qSize = 0;
			qFront = 0;
			qBack = -1;
		}

		size_t size()const{
			return qSize;
		}

		size_t capacity()const{
			return qCapacity;
		}

		bool empty()const{
			if(qSize == 0)
				return 1;
			else
				return 0;
		}

		const T& front()const{
			if(empty())	//function call
				throw underflow_error("error");
			else
				return qArray[qFront];
		}

		const T& back() const{
			if(empty())
				throw underflow_error("error");
			else
				return qArray[qBack];
		}

		void push(const T val){
			if(qCapacity == 0)
				reserve(1);
			if(qSize == qCapacity)
				reserve(2 * qCapacity);
			++qBack;
			qBack%=qCapacity;	
			qArray[qBack]=val;
			++qSize;
		}
	
		void pop(){
			if(qSize == 0)
				throw underflow_error("error");
			++qFront;
			--qSize;
		}

		void reserve(size_t n){
			if (n < qSize || n == qCapacity)
				return;

			T* tempArray = new T[n];

			for (size_t i = 0; i < qSize; i++)
			{
				tempArray[i] = qArray[(qFront+i)%qCapacity];	//special arrays
			}
			if(qArray)
				delete[] qArray;
			qFront=0;
			qBack=qSize-1;
			qCapacity = n;
			qArray = tempArray;
		}
};
#endif
