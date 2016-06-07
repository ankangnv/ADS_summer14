#include "MLtree.h"

LeftistNode* MinLeftistT::Childmerge(LeftistNode *n1, LeftistNode *n2)
{

	if(n1->returnlc() == NULL)
		n1->arrangelc(n2);
	else
	{

		n1->arrangerc(merge(n1->returnrc(),n2));
		if(n1->returnlc()->returnpl() < n1->returnrc()->returnpl())
			Childswap(n1);
		n1->arrangenpl(n1->returnrc()->returnpl() + 1);
	}
	return n1;
}


MinLeftistT::~MinLeftistT(void)
{
	delete MinLeftistT::r;
}


/*used in insert method and delete method to merge two trees*/

void MinLeftistT::merge(MinLeftistT & MLtree)
{
	if( this == &MLtree)
	{
		return;
	}
	MinLeftistT::r = MinLeftistT::merge(r, MLtree.r);
	MLtree.r = NULL;
}

/*used to insert elements into tree*/

void MinLeftistT::InsertNode(int x)
{
	LeftistNode *n = new LeftistNode(x, NULL, NULL, 0);
	MinLeftistT::r = MinLeftistT::merge(n, MinLeftistT::r);
}

LeftistNode* MinLeftistT::merge(LeftistNode *n1, LeftistNode *n2)
{
	if(n1 == NULL)
		return n2;
	if(n2 == NULL)
		return n1;
	if(n1->returnelement() < n2->returnelement())
		return Childmerge(n1,n2);
	else
		return Childmerge(n2,n1);
}

/*used to display the tree*/

void MinLeftistT::show(LeftistNode *root)
{
	Displayhelp *q = new Displayhelp();
	q->insertq(root);
	cout<<"[";
	while(q->qsize() != 0)
	{
		LeftistNode *o = q->removeq();
		cout<<o->element;
		if(o->returnlc() != NULL)
			q->insertq(o->returnlc());
		if(o->returnrc() != NULL)
			q->insertq(o->returnrc());
		if(q->qsize() != 0)
			cout<<",";
	}
	cout<<"]\n";
	delete q;
}

/*used to delete the minimum element in tree*/

void MinLeftistT::MinDelete()
{
	if(MinLeftistT::isEmpty()) return;
	LeftistNode *o = MinLeftistT::r;
	MinLeftistT::r= MinLeftistT::merge(r->returnlc(), r->returnrc());
	o->arrangelc(NULL);
	o->arrangerc(NULL);
	delete o;
}

void MinLeftistT::Childswap(LeftistNode *n)
{
	LeftistNode *left = n->returnlc();
	n->arrangelc(n->returnrc());
	n->arrangerc(left);
}

bool MinLeftistT::isEmpty()
{
	if(MinLeftistT::r == NULL)
		return true;
	return false;
}

MinLeftistT::MinLeftistT(void)
{
	MinLeftistT::r = NULL;
}


/*used to print the tree*/
void MinLeftistT::PrintLeftistTree()
{
	MinLeftistT::show(MinLeftistT::r);
}

void MinLeftistT::start(int *a, int b) 
{
	for(int i = 0; i < b; i++)
		MinLeftistT::InsertNode(*a++);
}
