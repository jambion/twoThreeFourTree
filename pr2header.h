/*
 * pr2header.h
 *      Author: Joshua
 */

#ifndef PR2HEADER_H_
#define PR2HEADER_H_
#include <iostream>
#include <string>
using namespace std;

struct btn{	//B-Tree Node Structure
	int counter;
	int root;
	btn *children[4];
	int key[3];
	bool leaf;


};

class btree{

public:
	btree();
	~btree();
	void createbTree();
	string bTreeSearch(btn* x, int k);
	void btreeInsert(int k);
	string search(int k);
	void btreeSplitChild(btn* x, int i);
	void btreeInsertNonfull(btn* x, int k);
	bool isKeyInTree(int k);








private:
	btn *T;


};


#endif /* PR2HEADER_H_ */
