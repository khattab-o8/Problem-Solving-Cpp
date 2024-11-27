#include <iostream>
#include <string>
using namespace std;

int ReadPositiveNumber(string Massage)
{
	int Number = 0;
	do
	{
		cout << Massage << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

void PrintInvertedLetterPattern(int Number)
{
	cout << "\n";

	int S = (Number - 1) + 65;

	for (int i = S; i >= 65; i--)
	{
		for (int j = 65; j <= i; j++)
		{
			cout << char(i);
		}
		cout << endl;
	}
}

int main()
{
	PrintInvertedLetterPattern(ReadPositiveNumber("Please enter a positive Number ?"));

	return 0;
}
