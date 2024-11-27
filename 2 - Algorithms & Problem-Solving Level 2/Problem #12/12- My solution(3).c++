#include <iostream>
#include <string>
using namespace std;

short ReadPositiveNumber(string Message)
{
	short Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

void PrintInvertedPattern(short Number)
{
	cout << "\n\n";

	for (short i = Number; i >= 1; i--)
	{
		for (short j = 1; j <= i ; j++)
		{
			cout << i << " ";
		}
		cout << "\n";
	}
}


int main()
{
	PrintInvertedPattern(ReadPositiveNumber("Please enter a positive Number ?"));

	return 0;
}
