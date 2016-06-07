
#pragma once
#include <iostream>
using namespace std;

#ifndef NULL
#define NULL 0
#endif

#ifndef _MLtree_H_
#define _MLtree_H_
#include "Node.h"
#include "Displayhelp.h"

/*Min Leftist tree intialization*/
class MinLeftistT
{
public:

	~MinLeftistT(void);
	void MinDelete();
	MinLeftistT(MinLeftistT & MLtree);
	void show(LeftistNode*);
	void PrintLeftistTree();
	void InsertNode(int x);
	void merge(MinLeftistT & MLtree);
	MinLeftistT & operator= (MinLeftistT & MLtree);
	MinLeftistT(void);
	void start(int *a, int b);
	bool isEmpty();
private:
	LeftistNode *Childmerge(LeftistNode *node1, LeftistNode *node2);
	LeftistNode *r;
	void Childswap(LeftistNode *node);
	LeftistNode *merge(LeftistNode *node1, LeftistNode *node2);
};

#endif
