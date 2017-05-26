/*
 * pr2Main.cpp
 *      Author: Joshua
 */

#include <iostream>
#include "pr2header.h"

using namespace std;

int main(){

	btree tree;





	tree.btreeInsert(50);
	tree.btreeInsert(40);
	tree.btreeInsert(60);
	tree.btreeInsert(30);
	tree.btreeInsert(70);
	tree.btreeInsert(10);
	tree.btreeInsert(20);
	//tree.btreeInsert(60);
	//tree.btreeInsert(70);
	/*
	tree.btreeInsert(80);
	tree.btreeInsert(64);
	tree.btreeInsert(55);
	tree.btreeInsert(62);
	tree.btreeInsert(66);
	tree.btreeInsert(75);
	tree.btreeInsert(83);
	tree.btreeInsert(86);
	*/





	cout<<"SEARCHING TREE:"<<endl;

	cout<<tree.search(50)<<endl;


	cout<<tree.search(20)<<endl;
	/*
	cout<<tree.search(80)<<endl;
	cout<<tree.search(50)<<endl;
	cout<<tree.search(70)<<endl;
	cout<<tree.search(85)<<endl;
	*/




	/*
	the result of tree.search(62) should be "62 64 66"
	the result of tree.search(20) should be "10 20"
	the result of tree.search(80) should be "60 70 80"
	the result of tree.search(50) should be "50"
	the result of tree.search(70) should be "60 70 80"
	the result of tree.search(85) should be "83 86"
	*/


	return 0;
}
