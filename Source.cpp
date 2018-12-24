#include <iostream>
#include <string>
using namespace std;

class CDisplay
{
public:
	void operator()(string input)const
	{
		cout << input << endl;
	}
};

int main()
{
	CDisplay mDisplay;
	mDisplay("Display this string! ");
	return 0;
}