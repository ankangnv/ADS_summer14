/*this is tha main entry point..Here we choose mode of operation.Depending on that the random mode or other two modes are choosed*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <ctime>


/*Header files included. Class declarations implemented*/
#include "MBheap.h"
#include "InsertData.h"
#include "MLtree.h"

#define RandomNumber 5000
#define RandomMode 1
#define LeftistMode 2
#define BinoMode 3
#define ErrMode 4



int ModeSet(int, char*);
void MinBinoHeap(char*);
void MinLeftistTree(char*);
int* GenSeq(int);
void RandomModeEval();
ParseFromFile* getNextInputFromFile(ifstream&);
void Callerror();

/*Following evaluates the mode switch function to pass the code flow to appropriate algorithm*/

int ModeSet(int argc, char* argv[])
{
	if(argc <= 1) return ErrMode;
	if(!strcmp(argv[1],"-r")) return RandomMode;
	else if(!strcmp(argv[1],"-il") && (argc > 2)) return LeftistMode;
	else if(!strcmp(argv[1],"-ib") && argc > 2) return BinoMode;
	else return ErrMode;
}


/*The Main Function*/

int main(int argc, char* argv[])
{


	int a = ModeSet(argc,argv);
	switch(a)
	{
	case RandomMode:
		RandomModeEval();
		break;
	case LeftistMode:
		MinLeftistTree(argv[2]);
		break;
	case BinoMode:
		MinBinoHeap(argv[2]);
		break;
	default:
		Callerror();
		break;
	}
	return 0;
}


/*User Input data from file */


ParseFromFile* getNextInputFromFile(ifstream& filehandl)
{
	ParseFromFile *b = new ParseFromFile();
	if(filehandl.eof())
	{
		b->TakeInputFormat('*');
		return b;
	}
	char a[20];
	filehandl.getline(a, 20);
	if(a[0] == 'I')
	{
		b->TakeInputFormat('I'); //'I' denotes Input text marker. The following numeric data is inserted.
		int g = 0, h = 2;
		while(a[h] != ' ' && a[h] != '\n' && a[h] != '\r' && a[h] != 0)
		{
			g = g*10 + a[h] - 48;
			h++;
		}

		b->arrele(g);
		return b;
	}
	else if(a[0] == 'D')//'D' denotes Delete minimum operation.
	{
		b->TakeInputFormat('D');
		return b;
	}
	else
		b->TakeInputFormat('E');//'E' Error mode. Control returns to main function.
	return b;
}


/*Algorithm flow for Min Leftist tree starts here*/

void MinLeftistTree(char* fn)
{
	ifstream filehandl(fn);
	if(filehandl == NULL)
	{
		cout<<"Error parsing input file.\n";
		return;
	}
	MinLeftistT *TreeLeftist1 = new MinLeftistT();

	while(true) 
	{
		ParseFromFile *a = getNextInputFromFile(filehandl);
		if(a->InputAccept() == 'D')
			TreeLeftist1->MinDelete();
		else if(a->InputAccept() == 'I')
			TreeLeftist1->InsertNode(a->takeelement());
		else if(a->InputAccept() == '*')
		{
			delete a;
			break;
		}
		delete a;
	}
	TreeLeftist1->PrintLeftistTree();
	delete TreeLeftist1;
	filehandl.close();
}


/*Algorithm flow for Min Binomial Heap starts here*/

void MinBinoHeap(char* fn)
{
	ifstream filehandl(fn);
	if(filehandl == NULL)
	{
		cout<<"Error parsing input file.\n";
		return;
	}
	MinBinomialHeap *HeapBino2 = new MinBinomialHeap();

	while(true) 
	{
		ParseFromFile *a = getNextInputFromFile(filehandl);
		if(a->InputAccept() == 'D') HeapBino2->MinDeleteBHeap();
		else if(a->InputAccept() == 'I') HeapBino2->InsertIntoBHeap(a->takeelement());
		else if(a->InputAccept() == '*')
		{
			delete a;
			break;
		}
		delete a;
	}
	HeapBino2->PrintBHeap();
	delete HeapBino2;
	filehandl.close();
}


void Callerror() 
{
	cout<<"\nUnknown Mode recognized\n\nPlease run ./heap -r or heap -il <FileName.txt> or heap -ib <FileName.txt> for Random, Leftist, Binomial Heap mode respectively\n";
}

/*if random mode is called the control enters into this*/

void RandomModeEval()
{
	int size = 7;
	int seq[] = {100,500,1000,2000,3000,4000,5000};

	cout<<"Leftist Tree and Binomial Heap performance after 5000(m) Delete min or Random insert operations \n\n";
	cout<<"After Pre-Insert (n)\t Min Leftist Tree (ms)\t Min Binomial Heap (ms)\n\n";

	long double ltree = 0;
	long double bheap = 0;
	clock_t start, end;
	for(int a = 0; a < size; a++)
	{
		long double TimeLeftist = 0;
		long double TimeBinoHeap = 0;

		for(int j = 0; j < 5; j++)
		{
			int *order = GenSeq(seq[a]);
			MinLeftistT *TreeLeftist = new MinLeftistT();
			TreeLeftist->start(order, seq[a]);
			MinBinomialHeap *heapBinomial = new MinBinomialHeap();
			heapBinomial->start(order, seq[a]);

			for(int i = 0; i < RandomNumber; i++)
			{
				if( rand()%2 == 0 )
				{
					int v = rand() % seq[a];
					start = clock();
					TreeLeftist->InsertNode(v);
					end = clock();
					TimeLeftist += (end - start);
					start = clock();
					heapBinomial->InsertIntoBHeap(v);
					end = clock();
					TimeBinoHeap += (end - start);
				}
				else
				{

					start = clock();
					TreeLeftist->MinDelete();
					end = clock();
					TimeLeftist += (end - start);

					start = clock();
					heapBinomial->MinDeleteBHeap();
					end = clock();
					TimeBinoHeap += (end - start);
				}
			}
			delete heapBinomial;
			delete TreeLeftist;
			delete[] order;
		}

		cout<<"\t"<<seq[a]<<"\t\t\t";
		cout<<(TimeLeftist / (5 * RandomNumber))<<"\t\t\t";
		cout<<(TimeBinoHeap / (5 * RandomNumber))<<"\n";
		ltree += TimeLeftist;
		bheap += TimeBinoHeap;
	}

	cout<<"\nThe running time per operation for Min Leftist Tree is ";
	cout<<(ltree / (5 * size *RandomNumber))<<" ms.\n";
	cout<<"\nThe running time per operation for Min Binomial Heap is ";
	cout<<(bheap / (5 * size * RandomNumber))<<" ms.\n";
}


int* GenSeq(int a)
{
	int *order = new int[a];
	for(int i = 0; i < a; i++){
		order[i] = i;
	}
	for(int j = 0; j < a; j++)
	{
		int k = order[j];
		int c = rand() % (a - j) + j;
		order[j] = order[c];
		order[c] = k;
	}
	return order;
}
