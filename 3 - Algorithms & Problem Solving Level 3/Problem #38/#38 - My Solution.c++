#include <iostream>
#include <string>
using namespace std;

string TrimLeft(string S)
{
	for (short i = 0; i < S.length(); i++)
	{
		if (S[i] != ' ')
		{
			return S.substr(i, S.length() - 1 - i);
		}
	}
	return "";
}

string TrimRight(string S)
{
	for (short i = S.length() - 1; i >= 0; i--)
	{
		if (S[i] != ' ')
		{
			return S.substr(0, i + 1);
		}
	}
	return " ";
}

string TrimAll(string S)
{
	//Method 1 :
	return (TrimLeft(TrimRight(S)));

	//Method 2 :
	//return (TrimRight(TrimLeft(S)));
}

int main()
{
	string S1 = "       Mohammed Abu-Hahdoud       ";

	cout << "\nOriginal Text : " << S1 << endl;

	cout << "\nTrim Left  = " << TrimLeft(S1);
	cout << "\nTrim Right = " << TrimRight(S1);
	cout << "\nTrim       = " << TrimAll(S1);


	system("pause > 0");
	return 0;
}