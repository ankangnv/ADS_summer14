/*initialization of Binimial node and its functions*/

#pragma once
#ifndef NULL
#define NULL 0
#endif

#ifndef _BinNode_H_
#define _BinNode_H_
class MinBinomialHeap;

class BinNode
{
private:
	BinNode *child, *link;
	int degree;
	int element;

public:
	~BinNode(void);
	void arrangelink(BinNode*);
	int returnelement();
	void arrangeelement(int);
	void arrangechild(BinNode*);
	BinNode* returnchild();
	BinNode* returnlink();
	BinNode(int, BinNode*, BinNode*, int);
	void arrangedegree(int);
	int returndegree();
	friend class MinBinomialHeap;
};

#endif
