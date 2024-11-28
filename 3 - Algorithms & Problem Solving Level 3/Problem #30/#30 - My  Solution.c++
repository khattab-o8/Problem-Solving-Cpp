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

char ReadCharacter()
{
	char Char1;
	cout << "\n\nPlease Enter a Character?\n";
	cin >> Char1;

	return Char1;
}

short CountLetters(string S1, char Char1)
{
	short counter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] == Char1)
		{
			counter++;
		}
	}
	return counter;
}

int main()
{
	string S1 = ReadString();
	char Char1 = ReadCharacter();

	cout << "\nLetter \'" << Char1 << "\' Count = " << CountLetters(S1, Char1);

	system("pause>0");
}