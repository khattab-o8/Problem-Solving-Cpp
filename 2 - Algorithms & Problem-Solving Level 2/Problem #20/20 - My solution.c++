#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int RandomNumber(int from,int to)
{
    int randnum = rand() % (to - from + 1) + from;

    return randnum;
}

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

char GetCharType(enCharType CharType)
{
	switch (CharType)
	{
	
	case enCharType::SmallLetter:
		return char(RandomNumber(97,122));
		break;

	case enCharType::CapitalLetter:
		return char(RandomNumber(65,90));
		break;

	case enCharType::SpecialCharacter:
		return char(RandomNumber(33, 47));
		break;

	case enCharType::Digit:
		return char(RandomNumber(48, 57));
		break;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	cout << GetCharType(SmallLetter) << endl;
	cout << GetCharType(CapitalLetter) << endl;
	cout << GetCharType(SpecialCharacter) << endl;
	cout << GetCharType(Digit) << endl;

    return 0;
}

