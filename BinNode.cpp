
#include "BinNode.h"

/*returns degree of the node*/

int BinNode::returndegree()
{
	return BinNode::degree;
}

BinNode::~BinNode(void)
{
}
/*returns the element*/

int BinNode::returnelement()
{
	return BinNode::element;
}

BinNode* BinNode::returnchild()
{
	return BinNode::child;
}

BinNode* BinNode::returnlink()
{
	return BinNode::link;
}

/*it sets degree*/

void BinNode::arrangedegree(int degree)
{
	BinNode::degree = degree;
}

void BinNode::arrangeelement(int element)
{ 
	BinNode::element = element;
}

BinNode::BinNode(int element, BinNode* child = NULL, BinNode* link = NULL, int degree = 0)
{
	BinNode::element = element;
	BinNode::child = child;
	BinNode::link = link;
	BinNode::degree = degree;
}

void BinNode::arrangelink(BinNode* link)
{
	BinNode::link = link;
}

void BinNode::arrangechild(BinNode* child)
{
	BinNode::child = child;
}



