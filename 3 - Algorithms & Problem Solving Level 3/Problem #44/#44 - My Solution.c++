#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string RemovePunctuations(string S)
{
	string NewString = " ";

	for (short i = 0; i < S.length(); i++)
	{
		if (!ispunct(S[i]))
			NewString += S[i];
	}

	return NewString;
}

int main()
{
	string S = "Welcome to Jordan, Jordan is a nice country; it's amazing.";

	cout << "\nOriginal String: \n" << S << endl;

	cout << "\n\nPunctuations Removed:\n" << RemovePunctuations(S) << endl;

	system("pause > 0");
	return 0;
}