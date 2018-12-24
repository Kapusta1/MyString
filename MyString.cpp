#include <iostream>
#include <string>
using namespace std;

class MyString
{
private:
	char * Buffer;
	MyString() :Buffer(NULL)
	{
		cout << "Default constructor called " << endl;
	}
public:
	MyString(const char * InitialInput)
	{
		cout << "Constructor called for: " << InitialInput << endl;
		if (InitialInput != NULL)
		{
			int len = strlen(InitialInput) + 1;
			Buffer = new char[len];
			strcpy_s(Buffer, len, InitialInput);
		}
		else
			Buffer = NULL;
	}
	MyString(const MyString &CopySource)           //constructor copy
	{
		cout << "Copy constructor to copy from: " << CopySource.Buffer << endl;
		if (CopySource.Buffer != NULL)
		{
			if (Buffer != NULL)
				delete[] Buffer;
			int len = strlen(CopySource.Buffer) + 1;
			Buffer = new char[len];
			strcpy_s(Buffer, len, CopySource.Buffer);
		}
		else
			Buffer = NULL;
	}

	MyString & operator =(const MyString & CopySource) //operator assignment copy
	{
		cout << "Copy assignment operator to copy from: " << CopySource.Buffer << endl;
		if ((this != &CopySource) && (CopySource.Buffer != NULL))
		{
			if (Buffer != NULL)
				delete[] Buffer;
			int len = strlen(CopySource.Buffer) + 1;
			Buffer = new char[len];
			strcpy_s(Buffer, len, CopySource.Buffer);
		}
		return *this;
	}
	MyString(MyString && MoveSource)                    //Move constructor
	{
		cout << "Move constructor to move frome: " << MoveSource.Buffer << endl;
		if (MoveSource.Buffer != NULL)
		{
			Buffer = MoveSource.Buffer;
			MoveSource.Buffer = NULL;
		}
	}
	MyString&operator=(MyString && MoveSource)        //operator assignment to move
	{
		cout << "Move assignment operator to move frome: " << MoveSource.Buffer << endl;
		if ((MoveSource.Buffer != NULL) && (this != &MoveSource))
		{
			delete Buffer;
			Buffer = MoveSource.Buffer;
			MoveSource.Buffer = NULL;
		}
		return *this;
	}
	char & operator [](int index)
	{
		int len = GetLength();
		if ((Buffer != NULL) && (index <= len))
			return Buffer[index];
	}
	const char & operator [](int index)const
	{
		int len = strlen(Buffer) + 1;
		if ((Buffer != NULL) && (index <= len))
			return Buffer[index];
	}
	MyString operator + (const MyString & AddThis)
	{
		cout << "operator + called: " << endl;
		MyString NewString;
		if (AddThis.Buffer != NULL)
		{
			int AddLen = strlen(AddThis.Buffer) + 1;
			NewString.Buffer = new char[GetLength() + AddLen];
			strcpy_s(NewString.Buffer, strlen(Buffer) + 1, Buffer);
			strcat_s(NewString.Buffer, strlen(Buffer) + AddLen, AddThis.Buffer);
		}
		return NewString;
	}
	~MyString()
	{
		if (Buffer != NULL)
			delete[] Buffer;
	}
	int GetLength() { return strlen(Buffer); }
	operator const char*() { return Buffer; }
};

int main()
{
	MyString Hello("Hello");
	MyString World(" World");
	MyString CPP(" of C++");

	MyString sayHelloAgain(" overwrite this");
	sayHelloAgain = Hello + World + CPP;
	return 0;
}