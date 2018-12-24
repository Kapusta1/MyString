#include <iostream>
#include <string>
using namespace std;

class MyString
{
private:
	char * Buffer;
public:
	MyString(const char * InitialInput)
	{
		if (InitialInput != NULL)
		{
			int len = strlen(InitialInput) + 1;
			Buffer = new char[len];
			strcpy_s(Buffer, len, InitialInput);
		}
		else
			Buffer = NULL;
	}
	MyString(const MyString &CopySource)
	{
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

	MyString & operator =(const MyString & CopySource)
	{
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
	cout << "Type a statement";
	string strInput;
	getline(cin, strInput);

	MyString yousaid(strInput.c_str());
	cout << "Using operator [] for display your input: " << endl;
	for (int Index = 0; Index < yousaid.GetLength(); ++Index)
		cout << yousaid[Index] << " ";
	cout << endl;

	cout << "Enter index 0- " << yousaid.GetLength() - 1 << ": ";
	int InIndex = 0;
	cin >> InIndex;
	cout << "Input character at sero-based position: " << InIndex;
	cout << " is: " << yousaid[InIndex] << endl;
	yousaid[5] = 't';

	return 0;
}