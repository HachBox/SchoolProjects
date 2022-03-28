#ifndef ASSIGNMENT6
#define ASSIGNMENT6
#include "assignment5.h"

class BST : public binTree {
    public:
	
	/**
	 * Constructor of the binTree
	 **/    
	BST() : binTree() {}	//constructor

        /**
	 * Inserting numbers into the binary tree
	 *
	 * When inserting the numbers, they get inserted in sorted order 
	 **/
	void insert( int );	//insert an item in the tree

	/*
	 * Searching through the binary tree, hence this assignment's name Binary Tree Search.   
	 */
        bool search( int );	//search an item in the tree

	/**
	 * Removes the binary tree created without creating segmentation faults
	 */
	bool remove( int );	//remove an item in the tree

        /**
	 * A sum of all the leaves of the left node
	 */
	int sumLeftLeaves();	//return the sum of values of left leaves
    private:
        void insert( Node*&, int );	//private version of insert(int)
        bool search( Node*&, int );	//private version of search(int)
        bool remove( Node*&, int );	//private version of remove(int)
        int sumLeftLeaves(Node*&);	//private version of sumLeftLeaves
};

#endif
