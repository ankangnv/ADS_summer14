
#pragma once
#ifndef _InsertData_H_
#define _InsertData_H_

class ParseFromFile
{
private:
	int abc;
	char it; 
public:

	ParseFromFile(char, int &);
	const int & takeelement();
	~ParseFromFile(void);
	void arrele(int);
	void TakeInputFormat(char);
	const char & InputAccept();
	ParseFromFile();

};

#endif
