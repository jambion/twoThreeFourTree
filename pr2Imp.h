/*
 * pr2Imp.cpp
 *      Author: Joshua
 */

#include <iostream>
#include <sstream>

#include "pr2header.h"

using namespace std;

btree::btree()	//default constructor
{
	createbTree();
}

btree::~btree()
{
	//delete T;
}

void btree::createbTree()	//Creates an empty b-tree
{
	T = new btn; //Allocates new node in regards to T
	T->leaf = true;
	T->counter = 0;

}


string btree::search(int k)	//Calls the "bTreeSearch function, so that T is used
{
	return bTreeSearch(T, k);
}

string btree::bTreeSearch(btn* x, int k)	//Function to search for "k" in the b-tree
{
	int i = 0;
	stringstream p; //stringstream variable p
	while (i < x->counter && k > x->key[i])
	{
		i++;
	}

	if (i < x->counter && k == x->key[i])	//if the key is found, we return
	{
		for (int j = 0; j < x->counter; j++)
		{
			p << x->key[j] << " ";
		}
		return p.str();
	}
	else if (x->leaf)	//We return NULL if x is a leaf
	{
		return "NULL";
	}
	else
	{
		return bTreeSearch(x->children[i], k);
	}
}

void btree::btreeInsert(int k)
{
	btn* r = T; //root node r declared as root T

	if (r->counter == 3){ //if the root node is full. 2T-1=3 for our 2-3-4 tree
		btn* s = new btn;
		T = s;
		s->leaf = false;
		s->counter = 0;
		s->children[0] = r;
		btreeSplitChild(s, 0);
		btreeInsertNonfull(s, k);

	}
	else{	//If the root node is not full, we call "btreeInsertNonfull"
		btreeInsertNonfull(r, k);
	}
}

void btree::btreeInsertNonfull(btn* x, int k)	//Inserts k into the tree rooted at the nonfull root node
{
	//cout<<"k is: "<<k<<endl;
	int i = x->counter - 1;

	if (x->leaf){

		while (i >= 0 && k < x->key[i]){
			x->key[i + 1] = x->key[i];
			i--;
		}
		x->key[i + 1] = k;
		x->counter++;

	}
	else{
		while (i >= 0 && k < x->key[i]){

			i--;
		}


		i++;
		if (x->children[i]->counter == 3){ //if the recursion will lead to a full child, we will split the child
			btreeSplitChild(x, i);
			if (k > x->key[i])
			{ //

				i++;
			}

		}

		btreeInsertNonfull(x->children[i], k); //recursion inserts k into its correct subtree
	}
}

void btree::btreeSplitChild(btn* x, int i)
{
	int t = 2; //t is the reduced children
	btn* z = new btn;
	btn* y = x->children[i];
	z->leaf = y->leaf;
	z->counter = t - 1;

	z->key[0] = y->key[t];



	if (!y->leaf){
		for (int k = 0; k < t; k++)
		{
			z->children[k] = y->children[k + t];
		}
	}

	y->counter = t - 1;
	for (int j = x->counter; j > i + 1; j--)
	{
		x->children[j] = x->children[j - 1];
	}
	x->children[i + 1] = z;

	for (int j = x->counter; j > i; j--)
	{

		x->key[j] = x->key[j - 1];

	}


	x->key[i] = y->key[t - 1];

	x->counter++;


}

