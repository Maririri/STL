#include "string.h"

class MyString
{
	char *m_pStr;
public:
	MyString(const char * = "default");

	~MyString() {delete[] m_pStr;}

	MyString(const MyString &);

	MyString(MyString &&other);

	MyString &operator=(const MyString &);

	MyString &operator=(MyString &&);

	friend std::ostream &operator<<(std::ostream &output, const MyString &ms);

};

std::ostream &operator<<(std::ostream &output, const MyString &ms)
{
	return output << ms.m_pStr;
}

MyString::MyString(const char *p)
{
	m_pStr = new char[strlen(p) + 1];
	strcpy(m_pStr, p);
}

MyString::MyString(const MyString &other)
{
	m_pStr = new char[strlen(other.m_pStr) + 1];
	strcpy(m_pStr, other.m_pStr);
}

MyString &MyString::operator=(const MyString &other)
{
	if(this != &other)
	{
		delete[] m_pStr;
		m_pStr = new char[strlen(other.m_pStr) + 1];
		strcpy(m_pStr, other.m_pStr);
	}
	return *this;
}

MyString &MyString::operator=(MyString &&other)
{
	if(this != &other)
	{
		delete[] m_pStr;
		m_pStr = other.m_pStr;
		other.m_pStr = nullptr;
	}
	return *this;
}

MyString::MyString(MyString &&other)
{
	m_pStr = other.m_pStr;
	other.m_pStr = nullptr;
}