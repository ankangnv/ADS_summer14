
#include "List.h"

BinNode* List::gbin(int j)
{
	if(List::ls == 0 || j >= List::ls)
		return NULL;
	listNode *it = List::f;
	for(int i = 0; i < j; i++)
		it = it->n;
	return it->e;
}

List::~List(void)
{
}

/*this function removes the node with same degree*/
BinNode* List::rnsd(BinNode *object)
{
	if(List::ls == 0 || List::f->e == object)
		return NULL;
	if(List::f->e->returndegree() == object->returndegree())
	{
		listNode *of = List::f;
		List::f = List::f->n;
		List::ls--;
		return of->e;
	}

	listNode *pr = List::f;
	listNode *ite = List::f->n;
	while(ite->e != object)
	{
		if(ite->e->returndegree() == object->returndegree()) break;
		pr = ite;
		ite = ite->n;
	}
	if(ite->e == object) return NULL;
	pr->n = ite->n;
	List::ls--;
	return ite->e;
}

void List::addto(BinNode *ele)
{
	if(f == NULL)
	{
		f = new listNode();
		f->e = ele;
		f->n = NULL;
	}
	else 
	{
		listNode* object = new listNode();
		object->e = ele;
		object->n = NULL;
		listNode *abc = f;
		while(abc->n != NULL)
			abc = abc->n;
		abc->n = object;
	}
	List::ls++;
}


List::List(void)
{
	List::f = NULL;
	List::ls = 0;
}


void List::takeaway(BinNode* object)
{
	if(List::ls == 0)
		return;
	if(List::f->e == object)
	{
		f = f->n;
		List::ls--;
		return;
	}
	listNode *pr = List::f;
	listNode *bc = List::f->n;
	while(bc != NULL)
	{
		if(bc->e == object) break;
		pr = bc;
		bc = bc->n;
	}
	if(bc != NULL)
	{
		pr->n = bc->n;
		List::ls--;
	}
}

int List::getListSize()
{
	return List::ls;
}

