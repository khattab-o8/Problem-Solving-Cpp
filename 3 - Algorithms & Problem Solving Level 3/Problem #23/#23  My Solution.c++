#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
	string Word = "";
	cout << "\nPlease Enter Your String ? \n";
	getline(cin, Word);

	return Word;
}

void PrintFirstLetterInEachWordInString(string S1)
{
	bool IsPreviousCharacterEqualSpace = true;

	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && IsPreviousCharacterEqualSpace == true)
		{
			cout << S1[i] << endl;
		}

		IsPreviousCharacterEqualSpace = (S1[i] == ' ') ? true : false;
	}
}

int main()
{
	string S1 = ReadString();


	cout << "\n\nFirst Letter Of This String : \n";
	PrintFirstLetterInEachWordInString(S1);


	system("pause > 0");
	return 0;
}


