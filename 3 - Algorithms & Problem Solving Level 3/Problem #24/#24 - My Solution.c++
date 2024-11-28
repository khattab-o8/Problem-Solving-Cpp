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

string UpperTheFirstLetterInEachWordInString(string S1)
{
	bool IsPreviousCharacterEqualSpace = true;

	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && IsPreviousCharacterEqualSpace == true)
		{
			S1[i] = toupper(S1[i]);
		}
		IsPreviousCharacterEqualSpace = (S1[i] == ' ') ? true : false;
	}

	return S1;
}

int main()
{
	string S1 = ReadString();


	cout << "\n\nString after conversion : \n" << 
		UpperTheFirstLetterInEachWordInString(S1);


	system("pause > 0");
	return 0;
}


