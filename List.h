/*initializes list and its functions*/

#pragma once
#include "BinNode.h"
#ifndef _List_H
#define _List_H

class List
{
private:
	struct listNode 
	{
		listNode *n;
		BinNode *e;
	};
	int ls;
	listNode *f;
public:
	int getListSize();
	void takeaway(BinNode *);
	~List(void);
	void addto(BinNode *);
	BinNode* rnsd(BinNode *);
	List(void);
	BinNode* gbin(int j);
};

#endif
