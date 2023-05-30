#include "MyString.h"



MyString::MyString()
{
	buffer = nullptr;
} 

MyString::MyString(const char* str)
{
	int length = 0;

	for (const char* i = &str[0]; *i == '\0'; i++)
		length++;

	buffer = new char[length + 1];

	for (int i = 0; i <= length; i++) {
		buffer[i] = str[i];
	}
	buffer[length] = '\0';
}

MyString::~MyString()
{
	delete[] buffer;
}

int MyString::getLength() const
{
	int length = 0;
	for (const char* i = &buffer[0]; *i != '\0'; i++)
		length++;

	return length;
}

void MyString::Clear()
{
	delete[] buffer;
	buffer = nullptr;
}

void MyString::operator = (const char* other)
{
	if (buffer != nullptr)
		delete[] buffer;
	int length = 0;
	for (const char* i = &other[0]; *i != '\0'; i++)
		length++;

	buffer = new char[length + 1];

	for (int i = 0; i <= length; i++) 
	{
		buffer[i] = other[i];
	}

	buffer[length] = '\0';

}




ostream& operator<<(ostream& os, MyString& str)
{
	if (str.buffer == nullptr)
		os << "";
	else
		os << str.buffer;
	return os;
}


istream& operator>>(istream& is, MyString& str)
{

	if (str.buffer != nullptr)
		delete[] str.buffer;
	char* input = new char[100];
	is >> input;

	int length = 0;
	for (const char* i = &input[0]; *i != '\0'; i++)
		length++;

	str.buffer = new char[length + 1];

	for (int i = 0; i < length; i++)
		str.buffer[i] = input[i];

	str.buffer[length] = '\0';

	delete[] input;

	return is;

}
