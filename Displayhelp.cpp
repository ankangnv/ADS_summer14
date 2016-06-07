/*implementation of queue to help in displaying the tree*/

#include "Displayhelp.h"

Displayhelp::Displayhelp(void)
{
	Displayhelp::r = NULL;
	Displayhelp::qs = 0;
}

Displayhelp::~Displayhelp(void)
{
}

/*similar to enqueue function*/

void Displayhelp::insertq(LeftistNode* ele)
{
	if(r == NULL)
	{
		r = new qObject();
		r->ab = ele;
		r->n = NULL;
	}
	else 
	{
		qObject* abc = new qObject();
		abc->ab = ele;
		abc->n = NULL;
		qObject *t = r;
		while(t->n != NULL)
			t = t->n;
		t->n = abc;
	}
	Displayhelp::qs++;
}

int Displayhelp::qsize()
{
	return Displayhelp::qs;
}

/*similar to dequeue operation*/

LeftistNode* Displayhelp::removeq()
{
	if(Displayhelp::qs != 0) 
	{
		qObject *o = r;
		qObject* n = r->n;
		r = n;
		qs--;
		return o->ab;
	}
	return NULL;
}
