/*initialization and function definitions of Displayheap*/

#pragma once
#include "Node.h"
#ifndef _Displayhelp_H_
#define _Displayhelp_H_

class Displayhelp
{
private:
	struct qObject 
	{
		qObject* n;
		LeftistNode* ab;
	};
	int qs;
	qObject* r;    
public:
	int qsize();
	Displayhelp(void);
	LeftistNode* removeq();
	~Displayhelp(void);
	void insertq(LeftistNode *);
};

#endif
