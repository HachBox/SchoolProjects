/***************************************************************************
POGRAM:    CSCI 340 Assignment6.cc
PROGRAMMER: Charles Scott
LOGON ID:   z1761100
DUE DATE:   3/228/2018
INSTRUCTOR: John Lehuta
FUNCTION:   This file implements the main functions of the Queue class
 ****************************************************************************/


#include <iostream>
#include "assignment5.hpp"
#include "assignment6.hpp"

using namespace std;

//public function implementation


void BST::insert( int x ) // insert an item in the tree
{

	insert(root,x);

}

bool BST::search( int x ) // search an item in the tree
{
return search(root,x);	



}

bool BST::remove( int x ) // remove an item in the tree
{

return	remove(root,x);



}

// returns true when successful
int BST::sumLeftLeaves() // return the sum of values
{
return	sumLeftLeaves(root);


}
	//private function implementation
void BST::insert( Node*& r , int x ) // private version of insert(int)
{
	if(r == nullptr){
		r = new Node;
		r -> value = x;
 		r->Left  = nullptr;
		r->Right = nullptr;
	}else
	if( x < r -> value)
		insert(r -> Left, x);  
	else insert(r -> Right,  x);



}

bool BST::search( Node*& N, int searchVar ) // private version of search(int)
{
	if(N == nullptr)
		return false;
	if (N -> value == searchVar)
		return true;
	if (N -> value < searchVar)
	return	search(N -> Right, searchVar);

	else return search(N -> Left,searchVar);
	








}
bool BST::remove( Node*& n , int x ) // private version of remove(int)
{
	//Find value searched for
	if (n == nullptr)
		return true;// didn't find searched value entry
	if (n -> value > x)
		return remove(n->Left,x );
	if (n -> value  < x) 
		return remove(n->Right,x);

	//Find value to replace
	//Find the right most value of the left subtree
	if(n -> Left == nullptr){
		Node* temp = n;
		n = n -> Right;

		delete temp;
		return true;
	}
	if(n -> Right == nullptr){
		Node* temp = n;
		n = n->Left;
		delete temp;
		return true;	
	}

	Node ** candidate = &n->Left;

	while((*candidate) -> Right != nullptr)
		candidate = &((*candidate) -> Right);


	//Do the Replace
	Node * temp;
	temp = n;
	n = *candidate;
	*candidate= (*candidate)->Left;
	n->Left = temp -> Left;
	n->Right = temp -> Right;

}
int BST::sumLeftLeaves( Node*& n) // private version of sumLeftLeaves
{	int res=0;
	if(n==nullptr)
		return 0;
	if (n -> Left != nullptr && n -> Left->Left == nullptr && n -> Left -> Right ==nullptr )
		res+= n->Left->value;
	//do we have a left child?
        res+=sumLeftLeaves(n->Left );
	res+=sumLeftLeaves(n->Right);

	return res;


}
