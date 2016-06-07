
/*intializes node and its functions*/
#pragma once

#ifndef NULL
#define NULL 0
#endif

#ifndef _Node_H_
#define _Node_H_

class MinLeftistT;

class LeftistNode
{
private:
	int null_path_length;
	LeftistNode *leftChild;
	int element;
	LeftistNode *rightChild;

public:
	LeftistNode* returnlc();
	~LeftistNode(void);
	int & returnpl();
	void arrangerc(LeftistNode*);
	LeftistNode* returnrc();
	LeftistNode(int &, LeftistNode*, LeftistNode*, int);
	void arrangeele(int &);
	void arrangelc(LeftistNode*);
	void arrangenpl(int);
	int & returnelement();
	friend class MinLeftistT;
};

#endif
