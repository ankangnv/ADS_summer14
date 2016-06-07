
#include "Node.h"   

LeftistNode::LeftistNode(int & element, LeftistNode* leftChild = NULL, LeftistNode* rightChild = NULL, int null_path_length = 0)
{
	LeftistNode::element = element;
	LeftistNode::leftChild = leftChild;
	LeftistNode::rightChild = rightChild;
	LeftistNode::null_path_length = null_path_length;
}

LeftistNode::~LeftistNode(void)
{
	if(LeftistNode::returnlc() != NULL)
		delete LeftistNode::returnlc();
	if(LeftistNode::returnrc() != NULL)
		delete LeftistNode::returnrc();
}

/*returns element of the node*/

int & LeftistNode::returnelement()
{
	return LeftistNode::element;
}

int & LeftistNode::returnpl()
{
	return LeftistNode::null_path_length;
}

LeftistNode* LeftistNode::returnlc()
{
	return LeftistNode::leftChild;
}

LeftistNode* LeftistNode::returnrc()
{
	return LeftistNode::rightChild;
}

void LeftistNode::arrangeele(int & element)
{
	LeftistNode::element = element;
}

void LeftistNode::arrangenpl(int null_path_length)
{
	LeftistNode::null_path_length = null_path_length;
}

void LeftistNode::arrangelc(LeftistNode* leftChild)
{
	LeftistNode::leftChild = leftChild;
}

void LeftistNode::arrangerc(LeftistNode* rightChild)
{
	LeftistNode::rightChild = rightChild;
}
