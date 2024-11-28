#include <string>
#include <iostream>
#include <cctype>
using namespace std;

string ReadString()
{
	string S1;
	cout << "Please Enter Your String ? " << endl;
	getline(cin, S1);

	return S1;
}

string LowercaseTheFirstLetterOfEachWord(string S1)
{
	bool IsFirstLetter = true;

	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && IsFirstLetter)
		{
			S1[i] = tolower(S1[i]);
		}

		IsFirstLetter = (S1[i] == ' ' ? true : false);
	}

	return S1;
}

int main()
{
	string S1 = ReadString();

	cout << "String after conversion: \n";
	S1 = LowercaseTheFirstLetterOfEachWord(S1);
	cout << S1 << endl;


	system("pause>0");
}