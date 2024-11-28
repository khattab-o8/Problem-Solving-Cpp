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

short CountCapitalAndSmallLetters(string S1, char Char1)
{
	short counter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] == toupper(Char1) || S1[i] == tolower(Char1))
		{
			counter++;
		}
	}
	return counter;
}

int main()
{
	system("color 4f");

	string S1 = ReadString();
	char Char1 = ReadCharacter();

	cout << "\nLetter \'" << Char1 << "\' Count = " << CountLetters(S1, Char1);

	cout << "\nLetter \'" << (char)tolower(Char1) << "\' Or \'"
	<< (char)toupper(Char1) << "\' Count = " 
	<< CountCapitalAndSmallLetters(S1, Char1);

	system("pause>0");
}