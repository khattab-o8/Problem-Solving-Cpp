#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString()
{
	string S1;
	cout << "Please Enter Your String? \n";
	getline(cin, S1);

	return S1;
}

short CapitalLettersCounter(string S1)
{
	short counter = 0;
	for (short i = 0; i < S1.length();i++)
	{
		if (isupper(S1[i]))
		{
			counter++;
		}
	}
	return counter;
}

short SmallLettersCounter(string S1)
{
	short counter = 0;
	for (short i = 0; i < S1.length();i++)
	{
		if (islower(S1[i]))
		{
			counter++;
		}
	}
	return counter;
}

int main()
{
	system("color 2f");

	string S1 = ReadString();

	cout << "\n" << "String Length = " << S1.length() << endl;

	short CounterForCapitalLetters = CapitalLettersCounter(S1);
	cout << "Capital Letters Count = " << CounterForCapitalLetters << endl;

	short CounterForSmallLetters = SmallLettersCounter(S1);
	cout << "Small Letters Count = " << CounterForSmallLetters << endl;



	system("pause>0");
}