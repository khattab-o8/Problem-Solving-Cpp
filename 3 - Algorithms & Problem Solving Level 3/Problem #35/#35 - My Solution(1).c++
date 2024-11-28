#include <string>
#include <iostream>
using namespace std;

string ReadString()
{
	string S1;
	cout << "Please Enter Your String? \n";
	getline(cin, S1);

	return S1;
}

void PrintEachWordInString(string S1)
{
	cout << "\n\nYour string words are: \n\n";

	bool IsFirstLetter = true;
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && IsFirstLetter)
		{
			cout << S1[i];
		}
		else
		{
			cout << endl;
		}

		IsFirstLetter = (S1[i] = ' ') ? true : false;
	}
}

int main()
{
	system("color 4f");

	string S1 = ReadString();
	PrintEachWordInString(S1);

	system("pause>0");
}