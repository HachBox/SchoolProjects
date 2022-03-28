/*
Program: Assignment 6
Programmer: Harry Chieng
P-ID: z1811457
Due: 3/28/2018
*/

#include <iostream>
#include "assignment5.h"
#include "assignment6.h"

using namespace std;

void BST::insert(int x) {	//getting the private insert function
	insert(root, x);
}

bool BST::search (int x) {	//getting the private search function
	return search(root, x);
}

bool BST::remove(int x) {	//getting the private remove function
	return remove(root, x);
}

int BST::sumLeftLeaves() {	//getting the sumLeftLeaves function
	return sumLeftLeaves(root);
}

void BST::insert(Node*& n, int x) {	//insert function with parameters
	if(n == nullptr) {	//root of that given subtree is nullptr	
		n = new Node;	//declaring that n is a new node
		n->data = x;	//declaring that the data = the integer x
		n->left = nullptr;
		n->right = nullptr;
	}
	else {
		if(n->data < x)
			insert(n->right, x);		//insert the integers x into the right subtree
		else
			insert(n->left, x);		//insert the integers x into the left subtree
	}
}

bool BST::search(Node*& n, int x) {	//search function
	if(n == nullptr) 		//checks if it is a nullptr
		return false;
	if(x < n->data)
		return search(n->left, x);
	if(x > n->data)
		return search(n->right, x);
	return true;
}

bool BST::remove( Node*& n, int x) {	//remove(int)
	//finds node
	if(n == nullptr) 
		return false;
	if (n->data > x) 
		return remove(n->left, x);
	if (n->data < x)
		return remove(n->right, x);

	//finds the right most left node
	if(n->left == nullptr) {
		Node*temp = n;
		n = n->right;
		delete temp;
		return true;
	}
	if(n->right==nullptr){
		Node* temp=n;
		n=n->left;
		delete temp;
		return true;
	}
	Node** candidate = &n->left;
	while((*candidate)->right != nullptr)
		candidate = &((*candidate)->right);

	//moves candidate and node then
	Node*temp = n;
	n = *candidate;
	*candidate = (*candidate)->left;
	n->left = temp->left;
	n->right = temp->right;
	delete temp;
	return true;
}

int BST::sumLeftLeaves(Node*& n) {	//private version of sumLeftLeaves
	int res = 0;
	if(n == nullptr)
		return 0;
	{
		if(n != nullptr && n->left != nullptr) {
			if(n->left->left == nullptr && n->left->right == nullptr)
				res += n->left->data;
			else
				res += sumLeftLeaves(n->left);
		}
		res += sumLeftLeaves(n->right);
	}
	return res;
}
