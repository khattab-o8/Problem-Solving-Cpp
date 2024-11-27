#include <iostream>
#include <string>
using namespace std;

enum enCharType { SamallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

int RandomNumber(int From, int To)
{
	int randnum = rand() % (To - From + 1) + From;

	return randnum;

}

char GetCharacterType(enCharType CharType)
{
	switch (CharType)
	{
	case enCharType::SamallLetter:
		return char(RandomNumber(97, 122));
		break;

	case enCharType::CapitalLetter:
		return char(RandomNumber(65, 90));
		break;

	case enCharType::SpecialCharacter:
		return char(RandomNumber(33, 47));
		break;

	case enCharType::Digit:
		return char(RandomNumber(48, 57));
		break;
	}
}

string GenarateWord(enCharType CharType,short Length)
{
	string word = "";
	for (int i = 1; i <= Length; i++)
	{
		word = word + GetCharacterType(CharType);
	}

	return word;
}

string GenerateKey()
{
	string Key = "";
	Key = GenarateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenarateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenarateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenarateWord(enCharType::CapitalLetter, 4);

	return Key;
}

void FillArrayWithGeneratedKey(string arr[100], short & arrLength)
{
	cout << "Please enter array elements ?\n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = GenerateKey();
	}
}

void PrintArray(string arr[100], short arrLength)
{
	cout << "\n";

	for (int i = 0; i < arrLength; i++)
	{
		cout << "Array [" << i << "] : " << arr[i] << "\n";
	}

	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	string arr[100];  short arrLength = 0;

	FillArrayWithGeneratedKey(arr, arrLength);
	PrintArray(arr, arrLength);


	return 0;
}

