#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

enum enCharacterType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

short ReadPositiveNumber(string Massage)
{
	short Number = 0;
	do
	{
		cout << Massage << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;

	return randNum;
}

char GetCharacterType(enCharacterType CharacterType)
{
	switch (CharacterType)
	{
	case enCharacterType::SmallLetter:
		return (char)RandomNumber(97, 122);

	case enCharacterType::CapitalLetter:
		return (char)RandomNumber(65, 90);

	case enCharacterType::SpecialCharacter:
		return (char)RandomNumber(33, 47);

	case enCharacterType::Digit:
		return (char)RandomNumber(48, 57);

	}
}

string GenerateKeySlot(enCharacterType CharacterType, short NumberOfSlots)
{
	string KeySlot;

	for (short i = 0; i < NumberOfSlots; i++)
	{
		KeySlot = KeySlot + GetCharacterType(CharacterType);
	}

	return KeySlot;
}

string GenerateKey(enCharacterType CharacterType)
{
	string Key;

	Key = GenerateKeySlot(CharacterType, 4) + "-";
	Key = Key + GenerateKeySlot(CharacterType, 4) + "-";
	Key = Key + GenerateKeySlot(CharacterType, 4) + "-";
	Key = Key + GenerateKeySlot(CharacterType, 4);

	return Key;
}

void PrintKeys(short Number, enCharacterType CharacterType)
{
	cout << "\nOutput:\n\n";

	for (short i = 1; i <= Number; i++)
	{
		cout << "Key [" << i << "]: " << GenerateKey(CharacterType) << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	short Number = ReadPositiveNumber("Please Enter How Many Keys to Generate ?");

	PrintKeys(Number,enCharacterType::CapitalLetter);

	system("pause>0");
}