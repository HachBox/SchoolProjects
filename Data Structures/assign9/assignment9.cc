#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "assignment9.h"
using namespace std;

graph::graph(const char* filename) {
	//This is the constructor. 
	//It reads from the input file of the graph with adjacency matrix representation
	//and builds the graph with adjacency list representation.
	ifstream matrixGraph(filename);
	if(!matrixGraph.is_open()) {
		std::cout << "File not opened" << filename << endl;
		return;
	}
	//This method sets the value of size,
	matrixGraph >> size;
	//builds the vectors labels and adj_list.
	for(int i=0; i < size; i++) {
		char temp;
		matrixGraph >> temp;
		labels.push_back(temp);		//putting it in the back of the vector
	}
	adj_list=vector<list<vertex>>(size);	//prealocates space for each vertex
	for(int i=0; i < size; i++) {
		char temp;	//read leter
		matrixGraph >> temp;
		for(int j=0; j < size; j++){	//for each column
			int isConnected;
			matrixGraph >> isConnected;
			//Add edges to adj_list[i]
			if(isConnected) {
				adj_list[i].push_back(j);	
			}
		}

	}
	//which records edges starting from vertex D, 
	//by adding values
	//1 and 4, which are indexes for vertices B and E.
}

int graph::get_size() const {
	return size;
}

vector<bool> visited;	//semi global to the internal functions
void graph::depth_first(vertex v) {
	visited[v] = true;
	cout << " " << labels[v] << " "; //visit the vertex
	for(vertex w:adj_list[v])	//for each vertex w adjacent to v
		if (!visited[w])
			depth_first(w);	
}

void graph::traverse() {
	visited=vector<bool>(size);
	//bool *visited; // pointer to create the array to keep
	// track of the visited vertices
	//visited = new bool[size];   //size = graph size
	for (int index = 0; index < size; index++)
		visited[index] = false;
	//for each vertex that is not visited, do a depth first traversal
	for (int index = 0; index < size; index++)
		if (!visited[index])
			depth_first(index);
	//delete[] visited;
	//This public function is used to traverse a graph and invokes the above depth_first method. 
	//At beginning of this method, you need to initialize 
	//the global variable(s) 
	//and object(s) used in depth_first. 
	//You will also need to display traverse result: 
	//the list of vertices in the order of their visit 
	//and the list of edges showing the path(s) of the traversal. 
}

void graph::print() const {
	//This function prints the adjacency list for the graph.
	//The following line is an example from an output.
	//D: B, E,
	//It indicates there are edges from vertex D to vertices B and E
	cout << "Number of vertices in the graph: " << size << endl;

	cout << "--------- graph -------" << endl;

	for(int count=0; count < size; ++count) {
		cout << labels[count] << ": ";
		for(int i:adj_list[count]) 
			cout << labels[i] << ", ";
		cout << endl;
	}
	cout << "--------- end of traverse --------" << endl;
}


#define ASSIGNMENT9_TEST
#ifdef 	ASSIGNMENT9_TEST

int main(int argc, char** argv) {
	if ( argc < 2 ) {
		cerr << "args: input-file-name\n";
		return 1;
	}

	graph g(argv[1]);

	g.print();

	g.traverse();

	return 0;
}

#endif
