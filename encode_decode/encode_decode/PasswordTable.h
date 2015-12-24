#ifndef PasswordTable_H
#define PasswordTable_H
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class PasswordTable
{
private:
	char table[95][95];		//char**table;
public:
	PasswordTable();
	~PasswordTable();
	void code();		//±àÂë
	void decode();		//½âÂë
};

#endif