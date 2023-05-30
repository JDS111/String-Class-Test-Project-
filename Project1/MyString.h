#pragma once


#include <iostream>
#include <ostream>
#include <istream>

using namespace std;

class MyString 
{
	friend ostream& operator<<(ostream& os, MyString& str);
	friend istream& operator>>(istream& is, MyString& str);
public:
	MyString();
	MyString(const char* str);
	~MyString();

	int getLength() const;

	void Clear();
	

	void operator = (const char* other);
private:
	char *buffer;
};

ostream& operator<<(ostream& os, MyString& str);
istream& operator>>(istream& is, MyString& str);