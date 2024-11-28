#include <string>
#include <iostream>
using namespace std;

char ReadChar()
{
	char Ch1;
	cout << "\nPlease Enter a Character?\n";
	cin >> Ch1;

	return Ch1;
}

bool CheckItIsAvowel(char Ch1)
{
	char SmallChar = tolower(Ch1);

	if (SmallChar == 97 || SmallChar == 101 || SmallChar == 105 || SmallChar == 111 || SmallChar == 117)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{

	char Ch1 = ReadChar();

	if (CheckItIsAvowel(Ch1))
	{
		system("color 2f");
		cout << "\nYES Letter \'" << Ch1 << "\' is vowel \n";
	}
	else
	{
		system("color 4f");
		cout << "\nNO Letter \'" << Ch1 << "\' is NOT vowel \n";

	}


	system("pause>0");
}