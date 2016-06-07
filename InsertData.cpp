
#include "InsertData.h"

ParseFromFile::ParseFromFile()
{
}

ParseFromFile::ParseFromFile(char iType, int & ele)
{
	it = iType; abc = ele;
}

ParseFromFile::~ParseFromFile(void)
{
}

const char & ParseFromFile::InputAccept()
{
	return it;
}

const int & ParseFromFile::takeelement()
{
	return abc;
}

void ParseFromFile::TakeInputFormat(char iType)
{
	it = iType;
}

void ParseFromFile::arrele(int ele)
{
	abc = ele;
}

