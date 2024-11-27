#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

enum enRandom { SmallLetter = 1 , CapitalLetter =2, SpecialCharacter = 3, Digit = 4 };

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;

	return randNum;
}

char Random(enRandom Random)
{
	switch (Random)
	{
	case enRandom::SmallLetter:
		return (char)RandomNumber(97, 122);

	case enRandom::CapitalLetter:
		return (char)RandomNumber(65, 90);

	case enRandom::SpecialCharacter:
		return (char)RandomNumber(33,47);

	case enRandom::Digit:
		return RandomNumber(48, 57);
	}
}

void PrintMultiplyRandom()
{
	cout << "\nOutput:\n";
	cout << Random(enRandom::SmallLetter) << endl;
	cout << Random(enRandom::CapitalLetter) << endl;
	cout << Random(enRandom::SpecialCharacter) << endl;
	cout << Random(enRandom::Digit) << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	PrintMultiplyRandom();


	system("pause>0");
}