/*
Programer: Harry Chieng
Date: 04/03/2018
Program: Number 7
Function: This function displays size number of elements contained in vector v starting at position pos. It shows 8 elements per line. Each item occupies 5 spaces.
*/

#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int HEAP_SIZE = 50;

// This function “heapifies” a tree at the root position r, assuming r’s two sub-trees are already heaps. 
// heap_size specifies the size of the whole heap contained by the vector (the heap starts at position 1 of the vector). 
// This function uses the function pointer compar to compare two elements. 
// This function can be implemented recursively.
void heapify( vector < int >& v, int heap_size, int r, bool(*compar)(int, int)) {
	if(r <= heap_size/2){						//gets the location by going to the first space with children on it (not a leaf)
		int lchild = r*2;					//measuring out, a child on the left would be on the 2n+0th of a given root
		int rchild = r*2 + 1;					//measuring out, a child on the right would be on the 2n+1th of a given root
		int bigChild;						

		if(rchild > heap_size)					//If the child on the right is greater than the heap_size
			bigChild = lchild;				
		else if(compar(v[lchild], v[rchild]))
			bigChild = lchild;
		else 
			bigChild = rchild;

		if(compar(v[bigChild], v[r])) {
			int temp = v[r];
			v[r] = v[bigChild];
			v[bigChild] = temp;
			heapify(v, heap_size, bigChild, compar);
		}
	}
}

//This function constructs a heap with heap_size elements in the vector v. Pay attention that elements start at position 1 (position 0 is wasted and ignored) in the vector. compar is a function pointer (predicate) to compare two integers. build_heap will invoke heapify specified below
void build_heap ( vector < int >& v, int heap_size, bool (*compar)(int, int)) {
	for(int x = heap_size/2; x != 0; x--) 
		heapify(v, heap_size, x, compar);
}

// This function compares two integers and returns true if e1 is less than e2. Otherwise it returns false. When this function is used as predicate in build_heap, a min heap will be constructed.
bool less_than( int e1, int e2 ) {
	return e1 < e2;
}

//This function compares two integers and returns true if e1 is greater than e2. Otherwise it returns false. When this function is used as predicate in build_heap, a max heap will be constructed.
bool greater_than( int e1, int e2 ) {
	return e1 > e2;
}

//This function extracts the root of the heap recorded in v, fills the root with the last element of the current heap, updates heap_size, “heapifies” at the root, and returns the old root value. This function will invoke heapify specified above.
int extract_heap( vector < int >& v, int& heap_size, bool(*compar)(int, int) ) {
	int temp = v[1];
	v[1] = v[heap_size];
	//v[heap_size + 1] = temp;
	heap_size--;
	heapify(v, heap_size, 1, compar);
	return temp;
}

//This function implement the heap sort algorithm. 
//At beginning the vector v contains a heap. 
//At the end of this function, vector v contains sorted elements. 
//Similar to build_heap, there is a predicate in the parameter list to specify how to compare two elements
//If less_than is passed in as argument here, the results are in ascending order. 
//If greater_than is used, the results are in descending order. 
//heap_sort will invoke extract_heap specified below. 
//You can use the STL algorithm reverse if necessary.
void heap_sort( vector < int >& v, int heap_size, bool (*compar)(int, int) ) {	
	int array_size = heap_size;
	build_heap(v, heap_size, compar);
	while(heap_size != 0) {
		int temp = extract_heap(v, heap_size, compar);
		v[heap_size + 1] = temp;
	}
	reverse(v.begin() +1, v.begin() + array_size+1);
}

//This function displays size number of elements contained in vector v starting at position pos. It shows 8 elements per line. Each item occupies 5 spaces.
void print_vector( vector < int >& v, int pos, int size ) {
	int i =0;	

	while(pos + i <= size)
	{
		cout<<setw(5)<<v[pos+i]<<" ";
		i++;
		if(i % 8 == 0)
			cout<<endl;

	}
	if(i % 8 != 0)
		cout<< endl;
}

int main() {
	// ------- creating input vector --------------
	vector<int> v;
	v.push_back(-1000000);    // first element is fake
	for (int i=1; i<=HEAP_SIZE; i++)
		v.push_back( i );
	random_shuffle( v.begin()+1, v.begin()+HEAP_SIZE+1 );

	cout << "\nCurrent input numbers: " << endl;
	print_vector( v, 1, HEAP_SIZE );

	// ------- testing min heap ------------------
	cout << "\nBuilding a min heap..." << endl;
	build_heap(v, HEAP_SIZE, less_than);
	cout << "Min heap: " << endl;
	print_vector( v, 1, HEAP_SIZE );
	heap_sort( v, HEAP_SIZE, less_than);
	cout << "Heap sort result (in ascending order): " << endl;
	print_vector( v, 1, HEAP_SIZE );

	// ------- testing max heap ------------------
	cout << "\nBuilding a max heap..." << endl;
	build_heap(v, HEAP_SIZE, greater_than);
	cout << "Max heap: " << endl;
	print_vector( v, 1, HEAP_SIZE );
	heap_sort( v, HEAP_SIZE, greater_than);
	cout << "Heap sort result (in descending order): " << endl;
	print_vector( v, 1, HEAP_SIZE );

	return 0;
}
