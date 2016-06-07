/*initialization of Min Binomial Heap and its functions*/

#pragma once
#include <iostream>
using namespace std;

#ifndef for
#define for if(0) {} else for
#endif

#ifndef _MBheap_H
#define _MBheap_H

#include "BinNode.h"
#include "List.h"

class MinBinomialHeap
{
private:
	BinNode *a;

public:
	MinBinomialHeap(void);
	~MinBinomialHeap(void);
	void start(int *list, int listsize);
	void PrintBHeap();

	void show(BinNode*);

	void InsertIntoBHeap(int);
	void MinDeleteBHeap();
};

#endif
