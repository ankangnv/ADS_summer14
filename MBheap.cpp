
#include "MBheap.h"

/*inserting elements into the tree*/

void MinBinomialHeap::InsertIntoBHeap(int e)
{
	if(MinBinomialHeap::a == NULL)
	{
		MinBinomialHeap::a = new BinNode(e, NULL, NULL, 0);
		MinBinomialHeap::a->arrangelink(MinBinomialHeap::a);
	}
	else
	{
		BinNode *b = a;
		BinNode *f = new BinNode(e, NULL, NULL, 0);
		BinNode *g = b->returnlink();
		b->arrangelink(f);
		f->arrangelink(g);
		if(f->returnelement() < MinBinomialHeap::a->returnelement())
			MinBinomialHeap::a = f;
	}
}

MinBinomialHeap::~MinBinomialHeap(void)
{
}

void MinBinomialHeap::start(int *a, int b)
{
	for(int i = 0; i < b; i++)
		MinBinomialHeap::InsertIntoBHeap(*a++);
}


/*used in displaying tree*/

void MinBinomialHeap::show(BinNode *a)
{


	List *b = new List();
	List *c = new List();
	int l = 1;

	BinNode *iterator = a->returnlink();
	b->addto(a);
	while(iterator != a)
	{
		b->addto(iterator);
		iterator = iterator->returnlink();
	}

	for(int i = 0; i < b->getListSize(); i++)
	{
		BinNode *node = b->gbin(i);
		BinNode *childNode = node->returnchild();
		if(childNode != NULL) 
		{
			BinNode *iterator = childNode;
			do
			{
				c->addto(iterator);
				iterator = iterator->returnlink();
			} while(iterator != childNode);
		}
	}

	while(b->getListSize() != 0)
	{
		cout<<"Level "<<l++<<": [";
		int p = b->getListSize();
		for(int i = 0; i < p - 1; i++)
		{
			cout<<b->gbin(i)->returnelement()<<",";
		}
		cout<<b->gbin(p - 1)->returnelement()<<"]\n";
		List *nc = new List();
		for(int i = 0; i < c->getListSize(); i++)
		{
			BinNode *n = c->gbin(i);
			BinNode *childNode = n->returnchild();
			if(childNode != NULL)
			{
				BinNode *iterator = childNode;
				do
				{
					nc->addto(iterator);
					iterator = iterator->returnlink();
				} while(iterator != childNode);
			}
		}
		b = c;
		c = nc;
	}
	delete b;
	delete c;
}

void MinBinomialHeap::PrintBHeap()
{
	MinBinomialHeap::show(MinBinomialHeap::a);
}

/*used to delete the minimum element of the tree*/

void MinBinomialHeap::MinDeleteBHeap()
{
	if(MinBinomialHeap::a == NULL)
		return;
	if(MinBinomialHeap::a->returnlink() == MinBinomialHeap::a)
	{
		BinNode *o = MinBinomialHeap::a;
		MinBinomialHeap::a = MinBinomialHeap::a->returnchild();
		if(MinBinomialHeap::a != NULL)
		{
			BinNode *c = MinBinomialHeap::a->returnlink();
			while(c != o->returnchild())
			{
				if(c->returnelement() < MinBinomialHeap::a->returnelement())
					MinBinomialHeap::a = c;
				c = c->returnlink();
			}
		}
		delete o;
	}
	else
	{

		List *l = new List();
		BinNode *fr = MinBinomialHeap::a->returnlink();
		while(fr != MinBinomialHeap::a)
		{
			l->addto(fr);
			fr = fr->returnlink();
		}
		BinNode *child = MinBinomialHeap::a->returnchild();
		if(child != NULL)
		{
			BinNode *m = child;
			do
			{
				l->addto(child);
				child = child->returnlink();
			} while(m != child);
		}


		for(int i = 0; i <l->getListSize(); i++)
		{
			BinNode *ln = l->gbin(i);
			ln->arrangelink(ln);
		}

		for(int i = 0; i < l->getListSize(); i++)
		{
			BinNode* n = l->gbin(i);
			BinNode* nwsd = l->rnsd(n);
			if(nwsd == NULL) continue;

			if(n->returnelement() < nwsd->returnelement())
			{
				BinNode *child = n->returnchild();
				if(child == NULL)
				{
					n->arrangechild(nwsd);
					nwsd->arrangelink(nwsd);
				}
				else
				{
					BinNode *childLink = child->returnlink();
					child->arrangelink(nwsd);
					nwsd->arrangelink(childLink);
				}
				n->arrangedegree(n->returndegree() + 1);
			}
			else
			{
				BinNode *child = nwsd->returnchild();
				if(child == NULL)
				{
					nwsd->arrangechild(n);
					n->arrangelink(n);
				}
				else
				{
					BinNode *childLink = child->returnlink();
					child->arrangelink(n);
					n->arrangelink(childLink);
				}
				l->takeaway(n);
				nwsd->arrangedegree(nwsd->returndegree() + 1);
				l->addto(nwsd);
			}

			i-=2;
		}

		MinBinomialHeap::a = l->gbin(0);
		for(int j = 0; j < l->getListSize() - 1; j++)
		{
			BinNode *no = l->gbin(j);
			BinNode *nno = l->gbin(j + 1);
			if(no->returnelement() < MinBinomialHeap::a->returnelement())
				MinBinomialHeap::a = no;
			no->arrangelink(nno);
		}
		BinNode *lein = l->gbin(l->getListSize() - 1);
		if(lein->returnelement() < MinBinomialHeap::a->returnelement())
			MinBinomialHeap::a = lein;
		lein->arrangelink(l->gbin(0));
		delete l;
	}
}
MinBinomialHeap::MinBinomialHeap(void)
{
	MinBinomialHeap::a = NULL;
}


