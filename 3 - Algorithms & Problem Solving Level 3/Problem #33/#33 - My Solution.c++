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

bool IsVowel(char ch1)
{
	ch1 = tolower(ch1);

	return ((ch1 == 'a') || (ch1 == 'e') || (ch1 == 'i') || (ch1 == 'o') || (ch1 == 'u'));
}

short CountVowels(string S1)
{
	short counter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (IsVowel(S1[i]))
		{
			counter++;
		}
	}
	return counter;
}

int main()
{
	string S1 = ReadString();

	cout << "\n\n" << "Number of vowels is : " << CountVowels(S1);

	system("pause>0");
}