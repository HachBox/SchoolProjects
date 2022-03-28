/*
Programmer: Harry Chieng
Program #5
Z-ID: z1811457
Due Date: 03/02/2018
*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "assignment5.h"

using namespace std;

const int MAX_SIZE = 40;
const int MAX_COUNT = 40;
const int WIDTH = 5;
const int ROW_SIZE = 8;

int mcount = 0;
int rcount = 0;

binTree::binTree() {
	root = nullptr;
}
//social constructor of binary Tree
void binTree::insert(int x) {
	insert(root, x);	
}
//public height function
int binTree::height() const {
	return height(root);
}
//public size function
unsigned binTree::size() const {
	return size(root);
}
//public inorder traversal
void binTree::inorder( void(*p)(int) ) {
	inorder(root,p);
}
//public preorder traversal
void binTree::preorder (void(*p)(int) ) {
	preorder(root, p);
}
//public postorder traversal
void binTree::postorder( void(*p)(int) ) {
	postorder(root, p);
}
//private insert function
void binTree::insert( Node*& r, int x) {
	if(r == nullptr) {	//root of that given subtree is nullptr
		r = new Node;	//declaring that r is a new node
		r-> data = x;	//declaring that the data = the integer x
		r->left=nullptr;
		r->right=nullptr;
	}
	else {
		if(size(r->right) < size(r->left))	//if right subtree is less than left subtree
			insert(r->right, x);		//insert the integers x into the right subtree
		else
			insert(r->left, x);		//insert the integers x into the left subtree
	}
}
//private height function
int binTree::height (Node* r) const {		
	if(r == nullptr) 			//if the node is nullptr
		return -1;			//return -1
	int rheight = height(r->right);		//initialize right height
	int lheight = height(r->left);		//initialize left height
	if(rheight < lheight)			//if height of right subtree is less than les subtree
			return lheight + 1;	//returns the height of left subtree + the root
		else
			return rheight + 1;	//returns the height of right subtree + the root
	}
//private size function
unsigned binTree::size(Node* r) const {
	if(r == nullptr)	//if the node is nullptr
		return 0;	//return 0 (false?)
	else
		return size(r->right) + size(r->left) + 1;	//returns size of right subtree + size of left subtree + root
}
//private inorder traversal
void binTree::inorder( Node* r, void(* p)(int) ) { 	//int is the integer of the function you're going to pass
	if (r != nullptr) {		//if the node doesn't equal nullptr
		inorder(r->left,p);	//uses inorder function to point the p to the left subtree
		p(r->data);		//calls the node
		inorder(r->right,p);	//uses inorder function to point the p to the left subtree
	}
}
//private preorder traversal
void binTree::preorder( Node* r, void(* p)(int) )  {
	if (r != nullptr) {		//if the node doesn't equal nullptr
		p(r->data);		//calls the node
		preorder(r->left,p);	//uses inorder function to point the p to the left subtree
		preorder(r->right,p);	//uses inorder function to point the p to the left subtree
	}
}
//private postorder traversal
void binTree::postorder( Node* r, void(* p)(int) ) {
	if (r != nullptr) {		//if the node doesn't equal nullptr
		postorder(r->left,p);	//uses inorder function to point the p to the left subtree
		postorder(r->right,p);	//uses inorder function to point the p to the left subtree
		p(r->data);		//calls the node
	}
}
//stuff that I didn't write, so here's documents that signify that I know what is here
void display(int d) {
	if ( mcount < MAX_COUNT ) {
		cout << setw(WIDTH) << d;
		mcount++;
		rcount++;
		if ( rcount == ROW_SIZE ) {
			cout << endl;
			rcount = 0;
		}
	}
}

//#define BINTREE_MAIN
#ifdef BINTREE_MAIN
int misin() {
	vector<int> v(MAX_SIZE);
	for (int i=1; i<MAX_SIZE; i++)
		v[i] = i;
	random_shuffle( v.begin(), v.end() );

	binTree bt;
	vector<int>::iterator it;
	for (it=v.begin(); it!=v.end(); it++)
		bt.insert( *it );

	cout << "Height: " << bt.height() << endl;
	cout << "Size: " << bt.size() << endl;
	cout << "In order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
	mcount = rcount = 0;
	bt.inorder( display );
	cout << "\n\nPre order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
	mcount = rcount = 0;
	bt.preorder( display );
	cout << "\n\nPost order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
	mcount = rcount = 0;
	bt.postorder( display );	

	cout << endl;
	return 0;
}

#endif
